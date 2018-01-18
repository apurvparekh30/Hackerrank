#include <bits/stdc++.h>
using namespace std;

void combination(string s,map<char,bool> charmap){
	int n = s.length();
	if(n!=0)
		cout<<s<<endl;
	
	char i;
	if(n==0){
		i='a';
	}
	else {
		i=s[n-1]+1;
	}
	for(;i<='z';i++){
		if(charmap[i]){
			string temp = s;
			s+=i;
			combination(s,charmap);
			s = temp;
		}
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		string s;
		cin>>s;
		map<char,bool> charmap;
		for(int i=0;i<s.length();i++){
			charmap[s[i]]=true;
		}
		string temp="";
		combination(temp,charmap);
	}
	return 0;
}