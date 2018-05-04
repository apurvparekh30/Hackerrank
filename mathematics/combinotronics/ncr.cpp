#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		n=n+1;
		vector<vector<long>> v(n,vector<long> (n));
		for(int i=0;i<n;i++){
			for(int j=0;j<=i;j++){
				if(j==0){
					v[i][j]=v[i][i-j]=1;
				}
                else {
                	v[i][j] = v[i][i-j] = (v[i-1][j-1]+v[i-1][j])%1000000000;
                }
				if(i==n-1){
					cout<<v[i][j]<<" ";
				}
			}
		}
		cout<<endl;
	}
	return 0;
}