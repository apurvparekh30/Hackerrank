#include <bits/stdc++.h>
using namespace std;

int getNumber(string s){
	int total=0;
	int size=s.length();
	for(int i=0;i<size;i++){
		int digit=stoi(s.substr(i,1));
		total=total+digit;
		if(total>9){
			total=getNumber(to_string(total));
		}
	}
	return total;
}
int main(){
	string s;
	int k;
	cin>>s>>k;
	int number = getNumber(s);
	number=number*k;
	number=getNumber(to_string(number));
	cout<<number;
	return 0;
}