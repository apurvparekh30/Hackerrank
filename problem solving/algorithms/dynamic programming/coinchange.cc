#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,m;
	cin>>n>>m;
	std::vector<long> c(m);
	for(int i=0;i<m;i++){
		cin>>c[i];
	}
	std::vector<long> v(n+1);
	v[0]=1;
	for(int i=0;i<m;i++){
		for(int j=c[i];j<=n;j++){
			v[j]=v[j]+v[j-c[i]];
		}
	}
	cout<<v[n];
	return 0;
}