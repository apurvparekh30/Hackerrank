#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin>>s;
	int n=s.length();
	vector<int> dp(n+1,-1);
	dp[0];
	int index=1;
	for(auto i:s){
		int no=i-'0';
		if(no%2==0){
			dp[index]=dp[index-1]+1;
		}
		else{
			dp[index]=dp[index-1];
		}	
		index++;
	}
	for(int i=1;i<=n;i++) {
		cout<<(dp[n]-dp[i-1])<<" ";
	}
	cout<<"\n";
	return 0;
}
