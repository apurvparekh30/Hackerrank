#include <bits/stdc++.h>
using namespace std;

bool mycompare(string a,string b) {
	int i=a.length();
	int j=b.length();

	if(i==j)	
		return a<b;
	return i<j;
}

int main() {
	int n;
	cin>>n;
	vector<string> v(n);
	for(int i=0;i<n;i++) {
		cin>>v[i];
	}
	sort(v.begin(),v.end(),mycompare);
	for(auto i:v) {
		cout<<i<<endl;
	}
	return 0;
}
