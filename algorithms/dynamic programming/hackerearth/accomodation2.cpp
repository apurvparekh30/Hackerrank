#include <bits/stdc++.h>
#define mod 1000000007
#define boost ios::sync_with_stdio(false);cin.tie(NULL);

using namespace std;

int rec(int m,int n,vector<vector<int>> &dp,vector<int> c) {
	if(dp[n][m-1])
		return dp[n][m-1];
	for(int i=0;i<m;i++) {
		dp[n][i]=((n-c[i]>=0)?rec(m,n-c[i],dp,c):dp[n][i-1])%mod;
	}
	return dp[n][m-1];
}

int main() {
	boost;
	int m,n;
	cin>>m>>n;
	vector<vector<int>> dp(n+1,vector<int>(m));
	for(int i=0;i<m;i++)	
		dp[0][i]=1;
	vector<int> c(m);
	for(int i=0;i<m;i++) {
		cin>>c[i];
	}
	cout<<rec(m,n,dp,c);
	return 0;
}
