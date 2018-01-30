#include <bits/stdc++.h>

using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int subS=-100000;
		int temp=0;
        bool flag = true;
		int maxSofar=-100000;
		int afteri=0;
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			int no;
			cin>>no;
			subS = max(subS,no);
			if(no>=0){
				temp=temp+no;
			}
			afteri=afteri+no;
			if(maxSofar<afteri){
				maxSofar=afteri;
			}
			if(afteri<0){
				afteri=0;
			}
		}
		if(subS >=0){
			subS=temp;
		}
		cout<<maxSofar<<" "<<subS<<endl;
	}
	return 0;
}