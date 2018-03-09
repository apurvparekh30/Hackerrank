#include <bits/stdc++.h>
using namespace std;

int bfs(list<int> lst[]) {
	priority_queue <int> pq;
	vector<bool> visited(101);
	pq.push(1);	
	vector<int> distance(101,101);
	distance[1]=0;
	while(!pq.empty()){
		int v=pq.top();
		pq.pop();
		visited[v]=true;
		for(auto i:lst[v]) {
			int newdist=distance[v]+1;
			if(distance[i]>newdist){
				distance[i]=newdist;
				pq.push(i);
			}
		}
	}
	if(distance[100]==101)
		return -1;
	else
		return distance[100];
}	

int main() {
	int t;
	cin>>t;
	while(t--) {
		list<int> lst[101];
		int m,n;
		cin>>n;
		map<int,int> ladder,snake;
		for(int i=0;i<n;i++) {
			int a,b;
			cin>>a>>b;
			ladder[a]=b;
		}
		cin>>m;
		for(int i=0;i<m;i++) {
			int a,b;	
			cin>>a>>b;
			snake[a]=b;
		}
		for(int i=1;i<101;i++) {
			if(!ladder[i] && !snake[i]) {
				for(int j=1;j<=6;j++) {
					if(i+j<=100) {
						if(ladder[i+j]) {
							lst[i].push_back(ladder[i+j]);
						}
						else if(snake[i+j]){
							lst[i].push_back(snake[i+j]);
						}
						else{
							lst[i].push_back(i+j);
						}
					}
				}
			}
		}
		int count=bfs(lst);
		cout<<count<<endl;
	}
	return 0;
}
