#include <bits/stdc++.h>
using namespace std;

void getAllPathsDFS(int s,int d,vector<bool> &visited,list<pair<int,int>> adj[],vector<int>& capacity,int weight) {
	visited[s]=true;
	if(s==d) {
		capacity.push_back(weight);
	}
	else{
		for(auto i:adj[s]) {
			int nextnode=i.first;
			int nextweight=i.second;
			if(!visited[nextnode]) {
				visited[nextnode]=true;
				getAllPathsDFS(nextnode,d,visited,adj,capacity,weight+nextweight);
			}
		}
	}
	visited[s]=false;
}


void getAllPaths(int s,int d,list<pair<int,int>> adj[],int n) {
	vector<bool> visited(n);
	vector<int> capacity;
	getAllPathsDFS(s,d,visited,adj,capacity,0);
	for(auto i:capacity) {
		cout<<i<<'\n';
	}
}
	
int main() {
	int t;
	cin>>t;
	while(t--) {
		int tno,n,m,s,d;
		cin>>tno>>n>>m>>s>>d;
		list<pair<int,int>> adj[n];
		for(int i=0;i<m;i++) {
			int from,to,weight;
			cin>>from>>to>>weight;
			adj[from].push_back(make_pair(to,weight));
		}
		getAllPaths(s,d,adj,n);	
	}
	return 0;
}
