#include <bits/stdc++.h>
#define boost ios::sync_with_stdio(false);cin.tie(NULL);

using namespace std;

bool isPrime(int no) {
	int t=sqrt(no);
	for(int i=2;i<=t;i++){
		if(no%i==0)
			return false;
	}
	return true;
}

int main() {
	int n;
	cin>>n;
	vector<int> v(n+1);
	vector<int> prefix(n+1);
	for(int i=1;i<=n;i++){
		cin>>v[i];
		prefix[i]=v[i]+prefix[i-1];
	}
	vector<int> primes;
	for(int i=2;i<=n;i++) {
		if(isPrime(i)){
			primes.push_back(i);
		}
	}
	
	vector<int> dp(n+1);
	dp[1]=0;
	for(int i=2;i<=n;i++) {
		//dp[i]=dp[i-1];
		for(int j=0;j<primes.size() && primes[j]<=i;j++){
			if(i==primes[j]) {
				dp[i]=max(dp[i-1],prefix[i]);
			}
			else {
				dp[i]=max(dp[i-1],prefix[i]-prefix[i-primes[j]]+dp[i-primes[j]-1]);
			}
		}
	}
	cout<<dp[n]<<'\n';
	return 0;
}
