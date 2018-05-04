#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin>>n;

	for(int i=1;i<=n;i++) {
		int total = 0;
		int t;
		cin>>t;
		while(t--){
			int type;
			cin>>type;
			int p,q;
			switch(type){
				case 1:
					cin>>p>>q;
					total+=p * q;
					break;
				default:
					cin>>p;
					total+=p;
			}
		}
		cout<<"Day "<<i<<": $"<<total<<".\n";
	}
	return 0;
}