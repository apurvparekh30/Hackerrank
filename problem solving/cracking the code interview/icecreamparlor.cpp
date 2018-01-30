#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;cin>>t;
	while(t--){
		long m;
		cin>>m;
		int n; cin>>n;
		vector<long> v(n+1);
		map<long,int> mp;
		for (int i = 1; i <=n; ++i){
			cin>>v[i];
			mp[v[i]]=i;
		}
		sort(v.begin(),v.end(),[](long a,long b){return a<b;});
		for(int i=1;i<=n;i++){
			if(mp[m-v[i]]){
				cout<<i<<" "<<mp[m-v[i]]<<endl;
			}
		}
	}
}