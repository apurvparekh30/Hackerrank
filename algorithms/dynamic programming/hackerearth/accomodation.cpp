#include <bits/stdc++.h>
#define boost ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod 1000000007

using namespace std;

int main() {
	boost;
	int m,n;
	cin>>m>>n;
	vector<int> c(m);
	for(int i=0;i<m;i++) {
		cin>>c[i];	
	}
	vector<vector<int>> dp(n+1,vector<int>(m));
	for(int i=0;i<m;i++)
		dp[0][i]=1;
	
	for(int i=1;i<=n;i++){
		for(int j=0;j<m;j++) {
			int x=(((i-c[j])>=0) ? dp[i-c[j]][j]:0)%mod;
			int y=((j>=1) ? dp[i][j-1]:0)%mod;
			dp[i][j]=x+y;
		}	
	}
	cout<<dp[n][m-1]<<'\n';

}
