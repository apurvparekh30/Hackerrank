#include <bits/stdc++.h>

using namespace std;

bool mycomp(long a,long b){
	return a>b;
}

int main(){
	int n;
	cin>>n;

	vector<long> c(n);

	for(int i=0;i<n;i++){
		cin>>c[i];
	}

	sort(c.begin(),c.end(),mycomp);

	long sum=0;
	for(int i=0;i<n;i++){
		sum=sum+(pow(2,i)*c[i]);
	}

	cout<<sum;
	return 0;
}