#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--) {
		int n,k;
		cin>>n>>k;
		vector<long long int> h(n+1);
		vector<long long int> dp(n+1);
		for(int i=1;i<=n;i++) {
			cin>>h[i];
		}
		long long int answer=0;
		for(int i=1;i<=n;i++) {
		    if(h[i]<=k) {
			dp[i]=dp[i-1]+h[i];
		    }
		    answer=max(answer,dp[i]);
		}
		cout<<answer<<"\n";	
	}
}

