#include <bits/stdc++.h>
#define boost ios::sync_with_stdio(false);cin.tie(NULL);
using namespace std;

int main() {
	boost;
	int n,m;
	cin>>n>>m;
	vector<int> v(m);
	map<int,bool> mp;
	for(int i=0;i<m;i++) {
		cin>>v[i];
		mp[v[i]]=true;
	}
	vector<int> s;
	int j=0;
	for(int i=1;i<=n;i++) {
		if(mp[i]) {
			while(v[j]<=i && j<m) {
				s.push_back(v[j]);
				j++;
			}
		}
		else {
			s.push_back(i);
		}
	}
	for(auto i:s) {
		cout<<i<<'\n';
	}
	/*vector<int> s;
	for(int i=1;i<=n;i++) {
		s.push_back(i);
	}
	do{
		bool flag= true;
		int j=0;
		for(auto i:s) {
			if(!mp[i])
				continue;
			if(i==v[j]) {
				j++;
			}	
			else {
				flag=false;
				break;
			}	
		}
		if(flag) {
			for(auto i:s) {
				cout<<i<<'\n';
			}
			break;
		}
	}while(next_permutation(s.begin(),s.end()));*/
	return 0;
}
