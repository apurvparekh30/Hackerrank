#include <bits/stdc++.h>
#define boost ios::sync_with_stdio(false);cin.tie(NULL);

using namespace std;

int main() {
	boost;
	int testcases;
	cin>>testcases;
	for(int t=1;t<=testcases;t++) {
		int n;
		cin>>n;
		vector<int> v(n);
		int errorIndex=n;
		for(int i=0;i<n;i++) {
			cin>>v[i];
		}
		bool flag=false;
		while(!flag) {
			errorIndex=n;
			flag=true;
			for(int i=0;i<n-2;i++) {
				if(i!=0) {
					if(v[i]<v[i-1]) {
						if(errorIndex>i-1)
							errorIndex=i-1;
					}
				}
				if(v[i]>v[i+2]) {
					flag=false;
					swap(v[i],v[i+2]);
				}
			}
		}
		if(errorIndex==n){
			int i=n-1;
			if(v[i]<v[i-1])
				errorIndex=i-1;
			i=n-2;
			if(v[i]<v[i-1])
				errorIndex=i-1;
		}
		if(errorIndex==n) {
			cout<< "Case #"<<t<<": OK\n";
		}
		else{
			cout<< "Case #"<<t<<": " << errorIndex<<'\n';
		}
		
	}
	return 0;
}
