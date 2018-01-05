#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin>>t;

	while(t--){
		char s[100];
		cin>>s;
		int len = strlen(s);

		bool flag = next_permutation(s,s+len);
		if(flag){
			cout<<s<<endl;
		}
		else {
			cout<<"no answer"<<endl;
		}
	}
	return 0;
}