#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;

	while(n!=0){
		vector<vector<long>> v(n+1,vector<long>(n+1));
		for(int i=0;i<=n;i++){
			v[0][i]=1;
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				v[i][j]=v[i][j-1]+v[i-1][j];
			}
		}
		cout<<v[n][n]<<endl;
		cin>>n;
	}
	return 0;
}