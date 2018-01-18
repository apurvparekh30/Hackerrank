#include <bits/stdc++.h>

using namespace std;

string* swap(string s[], int l,int r){
	string temp;
	temp=s[l];
	s[l]=s[r];
	s[r]=temp;
	return s;
}

void permute(string s[],int l,int r){
	if(l==r){
		for(int i=0;i<=r;i++){
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	else{
		for(int i=l;i<=r;i++){
			s=swap(s,l,i);
			permute(s,l+1,r);
			//s=swap(s,l,i);
		}
	}
}

int main() {
	string s[] = {"abc","jkl","xyz"};
	permute(s,0,2);
	return 0;
}