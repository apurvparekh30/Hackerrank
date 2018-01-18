#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> v(n);
		map<int,int> m;
		for(int i=0;i<n;i++){
			cin>>v[i];
			m[v[i]]++;
		}
		long long total=0;
		for(map<int,int>::iterator i=m.begin();i!=m.end();i++){
			if(i->second>1){
				int temp = i->second;
				total=total+(long long) temp * (temp -1);
			}
		}
		cout<<total<<endl;
	}
	return 0;
}