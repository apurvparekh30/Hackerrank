#include <bits/stdc++.h>

using namespace std;

int main() {
	while(1) {
		string str;
		getline(cin,str);
		if(str=="END") {
			break;
		}
		bool flag=true;
		unordered_map<char,bool> mp;
		for(char i:str) {
			if(i== ' ')
				continue;
			if(mp[i]) {
				flag=false;
				break;	
			}
			else {
				mp[i]=true;
			}
		}
		if(flag) {
			cout<<str<<'\n';
		}
	}
	return 0;
}
