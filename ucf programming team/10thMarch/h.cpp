#include <bits/stdc++.h>
using namespace std;

int main() {
	while(1) {
		int n;
		cin>>n;
		if(n==0)
			break;
		
		string no1,no2,no3;
		cin>>no1>>no2>>no3;
		vector<int> a(n),b(n),c(n);
		int hand=0;
		int count=0;
		for(int i=0;i<n;i++) {
			a[i]=no1[i]-'0';
			b[i]=no2[i]-'0';
			c[i]=no3[i]-'0';
		}
		for(int i=n-1;i>=0;i--) {
			int sum,rem;
			sum=a[i]+b[i]+hand;
			rem=sum%10;
			if(rem!=c[i]){
				count++;
			}
			else{
				hand=sum/10;
			}
		}
		cout<<count<<endl;
	}	
	return 0;
}
