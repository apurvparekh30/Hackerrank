#include <bits/stdc++.h>

using namespace std;


string isGrid(vector<string> v){
	int n=v[0].size();
	sort(v[0].begin(),v[0].end());

	for(int i=1;i<n;i++){
		sort(v[1].begin(),v[1].end());
		for(int j=0;j<n;j++){
			if(v[i][j] < v[i-1][j]){
				return "NO";
			}
		}
	}

	return "YES";
}

int main(){
	int t;
	cin>>t;

	while(t--){
		int n;
		cin>>n;
		vector<string> v(n);
		for(int i=0;i<n;i++){
			cin>>v[i];
		}
		cout<<isGrid(v);
	}

	return 0;
}