#include <bits/stdc++.h>

using namespace std;

bool mycompare(pair<string,int> a, pair<string,int> b) {
	return (a.second > b.second);
}

int main() {
	string s;
	map <string, int> mymap;
	string word;
	
	while(1){
		cin>>word;
		if(cin.eof()){
			break;
		}

		word.erase(std::remove_if(word.begin(), word.end(),[](char c) { return !(std::isalpha(c)); } ),word.end());
		transform(word.begin(), word.end(), word.begin(), ::tolower);
		mymap[word]++;

	}

	//std::set<pair<string,int>> setofWords (mymap.begin(), mymap.end(),mycompare);


	return 0;
}