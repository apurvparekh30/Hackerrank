#include <bits/stdc++.h>
using namespace std;
int dfs(int s,list<int> g[],vector<int> v,vector<bool>& visited,int n,bool buggy){
	visited[s]=true;	
	int count=0;
	if(v[s]==0){
		count++;
	}
	for(auto i=g[s].begin();i!=g[s].end();i++){
		if(*i==v[s]){
			if(!visited[*i]){
				count=count+dfs(*i,g,v,visited,n,buggy);
			}
		}
		else if(buggy){
			if(!visited[*i]){
				count=count+dfs(*i,g,v,visited,n,false);
			}
		}
	}
	return count;
}
int main(){
	int n,m; cin>>n>>m;
	list<int> g[n+1];
	vector<int> v(n+1);
	vector<bool> visited(n+1);
	for(int i=0;i<m;i++){
		int from,to;
		cin>>from>>to;
		if(from<0){
			v[abs(from)]=to;
			g[abs(from)].push_front(to);
		}
		else{
			g[from].push_back(to);
		}	
	}
	cout<<dfs(1,g,v,visited,n,true)<<endl;
	return 0;
}