#include <bits/stdc++.h>
using namespace std;

map<pair<int,int>,long> mp;

int getValue(int row,int col) {
	pair<int,int> curr=make_pair(row,col);
	if(col==0 || col==row) {
		mp[curr]=1;
		return mp[curr];
	}
	pair<int,int> parent=make_pair(row-1,col);
	if(!mp[parent]) {
		mp[parent]=getValue(row-1,col);
	}
	mp[curr]=mp[parent]+col;
	return mp[curr];
}
		
int main() {
	int t;
	cin>>t;
	//map<int,int> mp;
	while(t--) {
		int tno;
		cin>>tno;
		int n,m;
		cin>>n>>m;
		if(m>n) {
			cout<<tno<<" 0\n";
		}
		else {
			mp[make_pair(0,0)]=1;
			mp[make_pair(1,0)]=1;
			mp[make_pair(1,1)]=1;
			if(m<=n/2) {
				m=n-m;
			}
			cout<<tno<<" "<<getValue(n,m)<<'\n';
		}
	}
	return 0;
}	
