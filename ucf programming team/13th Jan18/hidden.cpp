#include <bits/stdc++.h>

using namespace std;

int main() {
	string p,m;
	cin>>p>>m;

	int plen = p.length();
	int mlen = m.length();

	map<char,int> mymap;
	for(int i=0;i<plen;i++) {
		mymap[p[i]]++;
	}
	int i=0;
	char nextChar;
	for(int j=0;j<mlen && i<plen;j++){
		nextChar = p[i];
		if(m[j]!=nextChar && mymap[m[j]]){
			cout<<"FAIL\n";
			return 0;
		}
		if(nextChar == m[j]){
			mymap[nextChar]--;
			i++;
		}
	}

	if(i>=plen){
		cout<<"PASS\n";
	}
	else {
		cout<<"FAIL\n";
	}
	return 0;
}