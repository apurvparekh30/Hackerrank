#include <bits/stdc++.h>
using namespace std;

class compare {
	public:
	bool operator()(pair<pair<int,int>,int> a,pair<pair<int,int>,int> b) {
		return a.first.second>b.first.second;
	}
};
void prims(int source,int n,list<pair<int,int>> ls[]) {
	priority_queue <pair<pair<int,int>,int>,vector<pair<pair<int,int>,int>>,compare> pq; 
	//priority_queue <pair<pair<int,int>,int>,vector<pair<pair<int,int>,int>>,mycomparator> pq;
	vector<bool> visited(n);
	visited[source]=true;
	for(auto i:ls[source]) {
		pq.push(make_pair(i,source));
	}
	while(!pq.empty()) {
		pair<pair<int,int>,int> newedge=pq.top();
		pq.pop();
		int s=newedge.second;
		int d=newedge.first.first;
		int c=newedge.first.second;	
		if(!visited[d]) {
			visited[d]=true;
			cout<< s << " " << d << " " << c <<endl;
			for(auto i:ls[d]) {
				if(!visited[i.first])
					pq.push(make_pair(i,d));
			}
		}
	}
}

int main() {
	int n,m;
	cin>>n>>m;
	list<pair<int,int>> ls[n];
	for(int i=0;i<m;i++) {	
		int from,to,cost;
		cin>>from>>to>>cost;
		ls[from].push_back(make_pair(to,cost));
		ls[to].push_back(make_pair(from,cost));
	}
	prims(0,n,ls);
	return 0;
}
