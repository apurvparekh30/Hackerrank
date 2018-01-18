#include <bits/stdc++.h>

using namespace std;

int number_needed(string a, string b) {
	map<char,int> ma,mb;
	for(int i=0;i<a.length();i++){
		ma[a[i]]++;
	}
	for(int i=0;i<b.length();i++){
		mb[b[i]]++;
	}   
	int count = 0;
	for (auto it = ma.begin(); it != ma.end(); ++it) {
    	char ch = it->first;
    	if(ma[ch] != mb[ch]){
    		count = count + max(ma[ch],mb[ch]) - min(ma[ch],mb[ch]);
    		ma[ch] = mb[ch] = 0;
    	}
  	}  
  	for (auto it = mb.begin(); it != mb.end(); ++it) {
    	char ch = it->first;
    	if(mb[ch] != ma[ch]){
    		count = count + max(ma[ch],mb[ch]) - min(ma[ch],mb[ch]);
    		ma[ch] = mb[ch] = 0;
    	}
  	}
  	return count;
}

int main(){
    string a;
    cin >> a;
    string b;
    cin >> b;
    cout << number_needed(a, b) << endl;
    return 0;
}
