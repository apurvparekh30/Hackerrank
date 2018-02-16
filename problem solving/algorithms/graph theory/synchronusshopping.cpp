#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m,k;
    cin>>n>>m>>k;
    int nodes=pow(2,k);
    vector<vector<int>> dist(n+1,vector<int> (nodes));
    vector<pair<int,int>> g[n+1];
    vector<int> maskatnode(n+1);
    for(int i=1;i<=n;i++){
        int types;
        cin>>types;
        for(int j=0;j<types;j++){
            int type;
            cin>>type;
            type--;
            maskatnode[i]|=(1<<type);
        }
    }
    for(int i=0;i<m;i++){
        int x,y,c;
        cin>>x>>y>>c;
        g[x].push_back(make_pair(y,c));
        g[y].push_back(make_pair(x,c));
    }

    for(int i=0;i<n+1;i++){
        for(int j=0;j<nodes;j++){
            dist[i][j]=1E9;
        }
    }

    set<pair<int,pair<int,int>>> st;
    st.insert(make_pair(1,make_pair(0,maskatnode[1])));
    dist[1][maskatnode[1]]=0;
    while(!st.empty()){
        pair<int,pair<int,int>> curr=*st.begin();
        int currnode=curr.first;
        int currcost=curr.second.first;
        int currmask=curr.second.second;
        st.erase(st.begin());
        for(int i=0;i<g[currnode].size();i++){
            int nextnode=g[currnode][i].first;
            int nextcost=g[currnode][i].second;
            int totalcost=nextcost+currcost;
            int newmask=currmask|maskatnode[nextnode];

            if(dist[nextnode][newmask]>totalcost){
                st.erase(make_pair(nextnode,make_pair(dist[nextnode][newmask],newmask)));
                dist[nextnode][newmask]=totalcost;
                st.insert(make_pair(nextnode,make_pair(dist[nextnode][newmask],newmask)));
            }
        }
    }
    int answer=1E9;
    for(int i=0;i<(1<<k);i++){
        for(int j=0;j<(1<<k);j++){
            if((i|j)==((1<<k)-1)){
                answer=min(answer,max(dist[n][i],dist[n][j]));
            }
        }
    }
    cout<<answer<<endl;
    return 0;
}