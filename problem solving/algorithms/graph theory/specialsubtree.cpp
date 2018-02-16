#include <bits/stdc++.h>
using namespace std;

map<int,int> mp;
map<int,int> size;


class CompareDist{
	public:
	bool operator() (pair<pair<int,int>,int> a, pair<pair<int,int>,int> b) {
		if(a.second==b.second){
			return (a.first.first+a.first.second+a.second > b.first.first+b.first.second+b.second);
		}
		return a.second>b.second;
	}

};
int find(int p){
	while(mp[p]!=p){
		p=mp[p];
	}
	return p;
}
void union_them(int p1,int p2) {
	if(size[p1]>size[p2]) {
		mp[p2]=p1;
		size[p1]++;
	}
	else {
		mp[p1]=p2;
		size[p2]++;
	}
}
int main() {
	int n,m;
	cin>>n>>m;
	priority_queue <pair<pair<int,int>,int> ,vector<pair<pair<int,int>,int>>,CompareDist> pq;
	for(int i=0;i<m;i++){
		int from,to,weight;
		cin>>from>>to>>weight;
		mp[from]=from;
		mp[to]=to;
		size[from]=1;
		size[to]=1;
		pq.push(make_pair(make_pair(from,to),weight));
	}
	long cost=0;
		
	while(!pq.empty()){
		pair<pair<int,int>,int> p=pq.top();
		pq.pop();
		int p1=find(p.first.first);
		int p2=find(p.first.second);
		if(p1!=p2){
			cost+=p.second;
			union_them(p1,p2);
		}		
	}
	/*while(!pq.empty()){
		pair<pair<int,int>,int> p=pq.top();
		pq.pop();
		cout<<p.first.first<<" "<<p.first.second<<" "<<p.second;	
	}*/
	cout<<cost<<endl;
	return 0;
}
