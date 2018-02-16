#include <bits/stdc++.h>
using namespace std;
int main(){
	string s;
	map<string,bool> mp;
	getline(cin,s);
	stringstream line(s);
	while(line>>s){
		if(mp[s]){
			cout<<"no"<<endl;
			return 0;
		}
		mp[s]=true;
	}
	cout<<"yes"<<endl;
	return 0;
}