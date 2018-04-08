#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		cout<<n<<' ';
		int r;
		cin>>r;
		string s;
		cin>>s;
		for(auto c:s) {
			string temp(r,c);
			cout<<temp;
		}
		cout<<'\n';
	}
}
