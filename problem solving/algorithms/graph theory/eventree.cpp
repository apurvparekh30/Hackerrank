#include <bits/stdc++.h>
using namespace std;

pair<int,int> DFS(int s, list<int> adj[]) {
	pair<int,int> p=make_pair(1,0);
	for(auto i=adj[s].begin();i!=adj[s].end();i++){
        pair<int,int> np=DFS(*i,adj);
        p.second+=np.second;
		if(np.first%2!=0){
			p.first++;
		}
		else {
			p.second++;
		}
	}
	return p;
}

int main() {
	int n,m;
	cin>>n>>m;
	list<int> adj[n+1];
	for(int i=0;i<m;i++) {
		int f,t;
		cin>>f>>t;
		adj[min(f,t)].push_back(max(f,t));
	}
	pair<int,int> p= DFS(1,adj);
	cout<<p.second<<endl;
}
