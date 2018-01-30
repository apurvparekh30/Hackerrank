#include <bits/stdc++.h>
using namespace std;

void swap(char *a,char *b){
	char temp=*a;
	*a=*b;
	*b=temp;
}

void permute(string s,int l,int r){
	if(l==r){
		cout<<s<<endl;
	}
	else{
		for(int i=l;i<=r;i++){
			swap(&s[l],&s[i]);
			permute(s,l+1,r);
		}
	}
	
}

int main(){
	string s="abc";
	int length=s.length();
	permute(s,0,length-1);
	return 0;
}