#include <bits/stdc++.h>
using namespace std;

int count_altering(string s,char a,char b) {
	int n=0;
	bool alast=false,blast=false;
	for(char i:s) {
		if(i==a){
			if(alast)
				return 0;
			n++;
			alast=true;
			blast=false;
		}
		if(i==b){
			if(blast)
				return 0;
			n++;
			blast=true;
			alast=false;
		}
	}
	return n;
}

int getLength(int n,string s,set<char> st){
	int m=0;
	for(auto i:st){
		for(auto j:st){
			if(i>=j)
				continue;
			m=max(m,count_altering(s,i,j));		
		}
	}	
	return m;
}
int main() {
	int n;
	string s;
	set<char> st;
	cin>>n>>s;
	for(char c:s){
		st.insert(c);
	}
	cout<<getLength(n,s,st);
}
