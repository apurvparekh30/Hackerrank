#include <bits/stdc++.h>
using namespace std;

int main() {
	int p;
	cin>>p;
	for(int i=1;i<=p;i++) {
		int tno;
		cin>>tno;
		int days;
		cin>>days;
		cout<<tno<<" "<< ((days*(days+1))/2)+days<<'\n';
	}
	return 0;
}
