#include <bits/stdc++.h>
using namespace std;

void permute(string s,int l,int r) {	
	if(l==r){
		cout<<s<<endl;
	}
	else{
		for(int i=l;i<=r;i++){
			swap(s[i],s[l]);
			permute(s,l+1,r);
		}
		//cout<<s<<endl;
	}
}
int main() {
	string s;
	cin>>s;
	int r=s.length()-1;
	int l=0;
	cout<<" Permutations are : " <<endl;
	permute(s,l,r);
	return 0;
}
