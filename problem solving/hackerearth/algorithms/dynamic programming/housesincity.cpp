#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<long> v(n+1);
		cin>>v[1];
		for(int i=2;i<=n;i++){
			long no;
			cin>>no;
			v[i]=no+v[i-1];
		}
		int q;
		cin>>q;
		int l,r;
		cin>>l>>r;
		while(q--){
			cout<<v[r]-v[l-1]<<endl;
		}
	}
    return 0;
}