#include <bits/stdc++.h>
using namespace std;


class mycomparator {
	public:
	bool operator()(pair<pair<int,int>,int> a,pair<pair<int,int>,int> b) {
		return a.first.second>b.first.second;
	}
};
void print_prims(vector<bool> visited,list<pair<int,int>> lst[]) {
	priority_queue<pair<pair<int,int>,int>,vector<pair<pair<int,int>,int>>,mycomparator> pq;
	int source=0,to,cost;
	for(auto i:lst[source])
		pq.push(make_pair(i,source));
	visited[source]=true;
	while(!pq.empty()){
		pair<pair<int,int>,int> p=pq.top();
		pq.pop();
		if(!visited[p.first.first]){
			source=p.second;
			to=p.first.first;	
			cost=p.first.second;
			cout<< source << " " << to<< " " <<cost<<endl;
			visited[to]=true;
			for(auto i:lst[to]){
				if(!visited[i.first]){
					pq.push(make_pair(i,to));

				}
			}
		}
	}	
	
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
	print_prims(visited,lst);
	return 0;
}
