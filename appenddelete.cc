#include <bits/stdc++.h> 

using namespace std;

int main() {
	string s,t;
	int k;
	cin>>s>>t;
	cin>>k;
	int i=0;
	while(s[i]==t[i]){
		i++;
	}
	int len1 = s.length();
	int len2 = t.length();

	int t1 = len1 - i;
	int t2 = len2 - i;

	int diff = (k - (t1 + t2));
	if(diff < 0 || diff % 2 != 0){
		cout << "No";
		return 0;
	}
	cout << "Yes";
	return 0;
}