#include <bits/stdc++.h>

using namespace std;

int main() {

	long no;
	vector<long> v(256);
	v[0]=2;
	no=3;
	for(long i=1;i<256;){
		bool flag = true;
		for(long j=2;j<=(no/2);j++){
			if(no%j==0){
				flag = false;
				break;
			}
		}
		if(flag){
			v[i]=no+v[i-1];
			i++;
		}
		no=no+2;
	}

	long t;
	cin>>t;

	while(t--){
		int n;
		cin>>n;
		cout<<v[n]<<endl;
	}

	return 0;
}