#include <bits/stdc++.h>
using namespace std;

int main() {
	while(1) {
		int c,d;
		cin>>c>>d;
		if(c==0 && d==0) {
			break;
		}
		int total=INT_MAX;
		total=min(total,(c*30+d*40));
		total=min(total,(c*35+d*30));
		total=min(total,(c*40+d*20));
		cout<<total<<endl;
	}
	return 0;
}
