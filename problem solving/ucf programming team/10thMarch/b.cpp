#include <bits/stdc++.h>
using namespace std;

int main() {
	while(1) {
		string str;
		getline(cin,str);
		if(str=="0000 0000 0000 0000")
			break;
		stringstream ss(str);
		int chunk;
		int sumodd=0,sumeven=0;
		while(ss>>chunk) {
			int index=4;
			while(chunk) {
				int rem=chunk%10;
				chunk=chunk/10;
				if(index%2==0) {
					sumeven+=rem;
				}
				else{
					rem*=2;
					if(rem>9) {
						rem-=9;
					}
					sumodd+=rem;
				}
				index--;
			}
		}
		int sum=sumodd+sumeven;
		if(sum%10==0) {
			cout<<"Yes"<<endl;
		}	
		else{
			cout<<"No"<<endl;
		}
	}
	return 0;
}
