#include<bits/stdc++.h>
using namespace std;

int dfs(vector<int> &v,list<int> adj[],int s,vector<bool> &visited){
	visited[s]=true;
	for(auto i:adj[s]){
		if(!visited[i])
			v[s]+=dfs(v,adj,i,visited);
	}
	return v[s];	
}

int main() {
	int n;
	cin>>n;
	vector<int> v(n+1);
	for(int i=1;i<=n;i++){
		cin>>v[i];
	}
	list<int> adj[n+1];
	set<pair<int,int>> st;
	for(int i=1;i<n;i++){
		int from,to;
		cin>>from>>to;
		st.insert(make_pair(from,to));
		adj[from].push_back(to);
		adj[to].push_back(from);
	}
	vector<bool> visited(n+1);
	v[1]=dfs(v,adj,1,visited);
	int m=INT_MAX;
	for(auto p:st){
		int v1,v2;
		v1=p.first;
		v2=p.second;
	
		int t1=v[1]-v[v2];
		int t2=v[v2];
		
		m=min(m,abs(t1-t2));
	}

	cout<<m<<endl;
	return 0;
}	
