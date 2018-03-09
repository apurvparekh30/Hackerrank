#include <bits/stdc++.h>
using namespace std;

bool ishackerrank(string s){
	string str="hackerrank";
	int n,m;
	n=s.length();
	m=10;
	if(n<m) {
		return false;
	}
	int j=0;
	for(int i=0;i<n && j<m;i++){
		if(s[i]==str[j]) {
			j++;
		}
	}
	if(j==m) {
		return true;
	}
	return false;
}

int main() {
	string s;
	int q;
	cin>>q;
	while(q--) {
		cin>>s;	
		if(ishackerrank(s)){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}	
	}
}
