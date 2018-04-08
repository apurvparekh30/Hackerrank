#include <bits/stdc++.h>

using namespace std;

class MyCompare{
	public:
	bool operator()(pair<int,int> a,pair<int,int> b) {
		if(a.second!=b.second)
			return a.second<b.second;
		return a.second>b.second;
	}
};

int main() {
	int t;
	cin>>t;
	for(int k=1;k<=t;k++) {
		long long d;
		cin>>d;
		string op;
		cin>>op;
		int scount=0;
		int ccount=0;
		long long strength=1;
		long long damage=0;
		priority_queue<pair<int,int>,vector<pair<int,int>>,MyCompare> pq;
		for(int i=0;i<op.length();i++) {
			if(op[i] == 'C') {
				strength=strength*2;
				ccount++;
			}
			else {
				scount++;
				damage=damage+strength;
				if(ccount>0)
					pq.push(make_pair(i,ccount));
			}
		}
		if(scount==0 || damage<=d) {
			cout<<"Case #"<<k<<": 0\n";
		}
		else if(scount>d) {
			cout<<"Case #"<<k<<": IMPOSSIBLE\n"; 
		}
		else {
			long long swaps=0;
			while(!pq.empty()) {
				pair<int,int> curr=pq.top();
				pq.pop();
				swaps++;
				int index=curr.first;
				int curr_ccount=curr.second;
				long long reduce = pow(2,curr_ccount)/2;
				damage=damage-reduce;
				if(damage<=d) {
					cout<< "Case #"<<k<<": "<<swaps<<'\n';
					break; 
				}
				if(curr_ccount-1>0) {
					pq.push(make_pair(index,curr_ccount-1));
				}
			}
		
			if(damage>d){
				cout<< "Case #"<<k<<": IMPOSSIBLE\n"; 
			}
		}
		
	}
	return 0;
}
