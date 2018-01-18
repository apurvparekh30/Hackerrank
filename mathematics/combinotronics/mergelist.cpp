#include <bits/stdc++.h>
#define x 1000000007
using namespace std;

int combination(int s, int m){
	s=s+1;
	vector<vector<long>> v(s,vector<long> (s));
	for(int i=0;i<s;i++){
		for(int j=0;j<=i;j++){
			if(j==0){
				v[i][j]=v[i][i-j]=1;
			}
            else {
            	v[i][j]=(v[i-1][j-1]+v[i-1][j])%x;
            }
			if(i==s-1 && j==m){
				return v[i][j];
			}
		}
	}

	return v[s-1][m];
} 

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		int s=n+m;
		cout<<combination(s,m)<<endl;
	}
	return 0;
}

