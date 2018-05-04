#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--) {
		int l;
		cin>>l;
		vector<int> upper(l);
		vector<int> lower(l);
		for(int i=0;i<l-1;i++) {
			cin>>upper[i];
		}
		for(int i=0;i<l-1;i++) {
			cin>>lower[i];
		}
		int result=l;
		for(int i=1;i<l;i++) {
			int temp=i+max(upper[i],lower[i]);
			result=max(temp,result);
		}
	}
	
	return 0;
}
