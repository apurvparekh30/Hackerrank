#include <bits/stdc++.h>
using namespace std;

int main() {
	long no;
	cin>>no;
	while(no!=0){
		while(no>9){
			cout<<no<<" ";
			long temp=1;
			while(no>0){
				temp=temp*(no%10);
				no=no/10;
			}
			no=temp;
		}
		cout<<no<<endl;
		cin>>no;
	}
	return 0;	
}