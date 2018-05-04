#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin>>n;		

	vector<pair<int,string>> v(n);
	for(int i=0;i<n;i++) {
		int a;
		string b;
		cin>>a>>b;
		v[i]=make_pair(a,b);
	}
	v.sort(v.begin(),
}
