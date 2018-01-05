#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
		int m,n;
		cin>>m>>n;
		map<int,int> ma,mc;
		vector<int> v(n+1);
		for(int i=1;i<=n;i++){
			int no;
			cin>>no;
			v[i] = no;
			ma[no]++;
			mc[no]=i;
		}
		for(int i=1;i<=n;i++){
			ma[v[i]]--;
			if(ma[m-v[i]] > 0){
				cout<<i<<" "<<mc[m-v[i]]<<endl;
				break;
			}
			ma[v[i]]++;
		}
	}
	return 0;
}