#include <bits/stdc++.h>
#define boost ios::sync_with_stdio(false);cin.tie(NULL);
using namespace std;

int rec(int rem){
	vector<int> dp(10);
	vector<int> prime={2,3,5,7};
	vector<int> nprime={4,6,8,9};
	for(int i=0;i<4;i++){ 
		dp[prime[i]]=1;
		dp[nprime[i]]=2;
	}
	if(rem==0)
		return 0;
	if(rem==1) {
		return dp[rem+7]-1;
	}	
	return dp[rem];
}

int main() {
	boost;
	int t;
	cin>>t;
	while(t--) {
		int x;
		cin>>x;
		if(x==1){
			cout<<"-1\n";
			continue;
		}	
		int result=(x/7)+rec(x%7);
		cout<<result<<'\n';
	}
	return 0;
}
