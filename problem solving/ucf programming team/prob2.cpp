#include <bits/stdc++.h>

using namespace std;

string getResult(string s1,string s2) {
	if(s1.length() != s2.length())
		return "NO";
	map<char,int> s1map;
	for(int i=0;i<s1.length();i++){
		s1map[s1[i]]++;
	}

	for(int i=0;i<s2.length();i++){
		if(!s1map[s2[i]]){
			return "NO";
		}
		s1map[s2[i]]--;
	}
	return "YES";
}

int main() {

	string s1,s2;
	int c;
	cin>>c;

	for(int i=1;i<=c;i++){
		cin>>s1>>s2;
		cout<<"Case #"<<i<<": "<<getResult(s1,s2)<<endl;
	}
	return 0;
}