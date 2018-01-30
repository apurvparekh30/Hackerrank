#include <bits/stdc++.h>
using namespace std;
bool checkB(int a,int b,int n,int m){
	if(a<0 || a>=n || b<0 || b>=m)
		return false;
	return true;
}
bool dfs(vector<vector<char>> &v,int s1,int s2,int k){
	if(v[s1][s2]=='*' && k==0)
		return true;
	if(v[s1][s2]=='X' || k<0)
		return false;
	//if(v[s1][s2]!='*')
		v[s1][s2]='X';
	int count=0;
	for(int i=-1;i<=1;i++){
		if(i!=0){
			int j=0;
			if(checkB(s1+i,s2+j,v.size(),v[0].size()) && (v[s1+i][s2+j]=='.' || v[s1+i][s2+j]=='*')){
				count++;
			}
		}
		else{
			for(int j=-1;j<=1;j+=2){
				if(checkB(s1+i,s2+j,v.size(),v[0].size()) && (v[s1+i][s2+j]=='.' || v[s1+i][s2+j]=='*')){
					count++;
				}
			}
		}
		if(count>1){
			k--;
			break;
		}
	}
	if(checkB(s1,s2-1,v.size(),v[0].size()) && dfs(v,s1,s2-1,k))
		return true;
	if(checkB(s1+1,s2,v.size(),v[0].size()) && dfs(v,s1+1,s2,k))
		return true;
	if(checkB(s1,s2+1,v.size(),v[0].size()) && dfs(v,s1,s2+1,k))
		return true;
	if(checkB(s1-1,s2,v.size(),v[0].size()) && dfs(v,s1-1,s2,k))
		return true;

	return false;

}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		vector<vector<char>> v(n,vector<char>(m));
		pair<int,int> s;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin>>v[i][j];
				if(v[i][j]=='M'){
					s.first=i;
					s.second=j;
				}
			}
		}
		int k;
		cin>>k;
		if(dfs(v,s.first,s.second,k)){
			cout<<"Impressed\n";
		}
		else{
			cout<<"Oops!\n";
		}
	}
	return 0;
}