#include <bits/stdc++.h>
using namespace std;

int isanagrams(string s1,string s2,int len) {
	map<char,int> mp;
	int count=0;
	int n=s2.length();
	for(auto i:s1) {
		mp[i]++;
	}
	bool flag;
	for(int i=0;i<=n-len;i++){
		string temp=s2.substr(i,len);
		flag=true;
		map<char,int> temp_mp=mp;
		for(char c: temp) {
			if(temp_mp[c]>0)
			{
				temp_mp[c]--;
			}
			else {
				flag=false;
				break;
			}
		}
		if(flag)
			count++;
	}
	return count;
}	
	

int main() {
	int t;
	cin>>t;
	while(t--) {
		string s;
		cin>>s;
		int count=0;
		int n=s.length();
		for(int i=1;i<=n;i++) {
			for(int j=0;j<n-i;j++) {
				string s1,s2;
				s1=s.substr(j,i);
				s2=s.substr(j+1);
				//cout<< s << " " << s1 << " " << s2<<endl;
				count+=isanagrams(s1,s2,i);
				
			}
		}	
		cout<< count<<endl;
	}
	return 0;
}
