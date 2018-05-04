#include <bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	list<int> l;
	int carry = 0;
	for(char c:s){
		l.push_back(c-48);
	}
	for(auto i:l){
		cout<<i<<" ";
	}
	return 0;
}