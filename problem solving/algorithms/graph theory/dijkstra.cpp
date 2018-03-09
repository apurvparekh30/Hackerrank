#include <bits/stdc++.h>
using namespace std;


class mycomparator {
	public:
	bool operator()(pair<pair<int,int>,int> a,pair<pair<int,int>,int> b) {
		return a.first.second>b.first.second;
	}
};
void dijkstra(int n,vector<bool> visited,list<pair<int,int>> lst[]) {
	priority_queue<pair<pair<int,int>,int>,vector<pair<pair<int,int>,int>>,mycomparator> pq;
	vector<int> distance(n,INT_MAX);
	int source=0,to,cost;
	distance[source]=0;
	for(auto i:lst[source])
		pq.push(make_pair(i,source));
	visited[source]=true;
	while(!pq.empty()){
		pair<pair<int,int>,int> p=pq.top();
		pq.pop();
		source=p.second;
		to=p.first.first;
		cost=p.first.second;
		distance[to]=min(distance[to],distance[source]+cost);
		if(!visited[to]){
			visited[to]=true;
			//distance[to]=distance[source]+cost;
			for(auto i:lst[to]){
				if(!visited[i.first]){
					pq.push(make_pair(i,to));
				}
			}
		}
	}	
	cout<< "Distace from source: "<<endl;
	for(auto i:distance) {
		cout<< " "<<i;
	}
	cout<<endl<<endl;
}
int main() {
	int n,m;
	cin>>n>>m;
	vector<bool> visited(n+1);
	list<pair<int,int>> lst[n+1];
	for(int i=0;i<m;i++) {
		int from,to,cost;
		cin>>from>>to>>cost;
		lst[min(from,to)].push_back(make_pair(max(from,to),cost));
	}
	cout<<endl<<endl;
	dijkstra(n,visited,lst);
	return 0;
}
