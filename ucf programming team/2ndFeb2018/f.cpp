#include <bits/stdc++.h>
using namespace std;
int main(){
	string a,b;
	cin>>a>>b;
	a='X'+a+'Y';
	b='Z'+b+'Z';

	int n=a.length();
	int i=1;
	while(a[i]==b[i]){
		i++;
	}
	int j=n-2;
	while(a[j]==b[j]){
		j--;
	}
	int revlen=(j-i)+1;
	string substring_a=a.substr(i,revlen);
	string substring_b=b.substr(i,revlen);
	reverse(substring_a.begin(),substring_a.end());

	if(substring_a!=substring_b){
		cout<<0<<endl;
	}
	else{
		int count=1;
		while(a[i-count]==b[j+count]){
			count+=1;
		}
		cout<<count<<endl;
	}
	return 0;
}