#include <bits/stdc++.h>

using namespace std;

int main() {
	int p;
	cin>>p;
	while(p--) {
		int tno;
		cin>>tno;
		int b;
		cin>>b;
		unsigned int n;
		cin>>n;
		if(b>n){
			cout<<tno<<" "<<n*n<<'\n';
			continue;
		}
		long int sq=b;
		int i=2;
		for(;sq<=n;i++) {
			sq=(long int) pow(b,i);
		}
		int exp=i-2;
		unsigned answer=0;
		while(exp>=0) {
			sq=(long int ) pow(b,exp);
			int q=n/sq;
			answer+=q*q;
			n=n%sq;
			exp--;
		}	
		cout<<tno<<" "<<answer<<'\n';
	}
	return 0;
}
