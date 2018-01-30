#include <bits/stdc++.h>
using namespace std;
int main(){
	string s1,s2;
	cin>>s1>>s2;
	unsigned long long sz1,sz2; 
	sz1=s1.length();
	sz2=s2.length();
	const int bitsize = INT_MAX;
	bitset<bitsize> a(s1);
	bitset<bitsize> b(s2);

	cout<<(b^=a);
	return 0;	
}