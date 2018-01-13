#include <bits/stdc++.h>

using namespace std;

void getDistance(vector<vector<int>> gv, int distance[], int s, int n) {

	vector<bool> visited(n+1);
	queue <int> q;
	q.push(s);
	visited[s]=true;
	while(!q.empty()){
		int front=q.front();
		q.pop();
		for(vector<int>::iterator i=gv[front].begin();i!=gv[front].end();i++){
			if(!visited[*i]){
				q.push(*i);
				visited[*i]=true;
				distance[*i]=distance[front]+6;
			}
		}
	}
}

int main() {
	int q;
	cin>>q;

	while(q--){
		int n,m;
		cin>>n>>m;
		vector<vector<int>> gv(n+1,vector<int>(n+1));

		for(int i=0;i<m;i++){
			int a,b;
			cin>>a>>b;
			gv[a].push_back(b);
			gv[b].push_back(a);
		}
		int s;
		cin>>s;
		int distance[n+1];
		memset(distance,0,sizeof(distance));
		getDistance(gv,distance,s,n);
		for(int i=1;i<=n;i++){
			if(i!=s) {
				if(distance[i] == 0){
					cout<<"-1"<<" ";
				}
				else
					cout<<distance[i]<<" ";
			}
		}

		cout<<endl;	
	}

	return 0;
}