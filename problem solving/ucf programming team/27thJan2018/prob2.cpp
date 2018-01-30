#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		bool flag=true;
		vector<vector<int>> v(n,vector<int>(n));
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin>>v[i][j];
			}
		}
		int m=0;
		for(int i=0;i<n;i++){
			m+=v[0][i];
		}
		for(int i=1;i<n;i++){
			int sum=0;
			for(int j=0;j<n;j++){
				sum+=v[i][j];
			}
			if(sum!=m){
				flag=false;
				break;
			}
		}
		if(!flag){
			cout<<"no"<<endl;
			continue;
		}
		for(int i=0;i<n;i++){
			int sum=0;
			for(int j=0;j<n;j++){
				sum+=v[j][i];
			}
			if(sum!=m){
				flag=false;
				break;
			}
		}
		if(!flag){
			cout<<"no"<<endl;
			continue;
		}
		int sum=0;
		for(int i=0,j=0,k=n-1;i<n;i++,j++,k--){
			sum+=v[i][j];
			sum+=v[i][k];
		}
		if(sum!=2*m){
			cout<<"no"<<endl;
			continue;
		}
		cout<<"yes"<<endl;
	}
	return 0;
}