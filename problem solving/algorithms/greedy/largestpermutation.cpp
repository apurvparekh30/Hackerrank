#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,k;
	cin>>n>>k;
	vector<int> v(n);
	vector<int> index(n+1);
	for(int i;i<n;i++){
		cin>>v[i];
		index[v[i]]=i;
	}
	int i=0;
	while(i<n && k){
		if(v[i]==n-i){
            i++;  
			continue; 
        }
		int temp=v[index[n-i]];
		v[index[n-i]]=v[i];
		v[i]=temp;
		k--;
		i++;
	}
	for(int i:v){
		cout<<i<<" ";
	}
	cout<<endl;
	return 0;
}