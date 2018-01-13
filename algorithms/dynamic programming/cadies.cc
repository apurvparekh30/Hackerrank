#include <bits/stdc++.h>

using namespace std;

int main(){

	int n;
	cin>>n;
	vector<int>v(n);
	for (int i = 0; i < n; ++i)
	{
		cin>>v[i];	
	}
	vector<long> dp(n,1);
	for(int i=1;i<n;i++){
		if(v[i-1]<v[i]){
			dp[i]=dp[i] + dp[i-1];
		}
	}

	for(int i=n-2;i>=0;i--){
		if(v[i] > v[i+1] && dp[i]<=dp[i+1]){
			dp[i] = dp[i+1] + 1;
		}
	}
	long sum=0;
	for(int i=0;i<n;i++){
		sum = sum + dp[i];
	}

	cout << sum;
	return 0;
}