#include <bits/stdc++.h>
using namespace std;

int main() {
	int p;
	cin>>p;
	while(p--) {
		int tno;
		cin>>tno;
		int m;
		cin>>m;
		long double x;
		cin>>x;
		//cout<<x;
		int a=0,b=1,c=1,d=1;
		bool flag=false;
		while(b<=m && d<=m) {
			long double median=(long double)(a+c)/(b+d);
			if(b == 755304 || d == 755304) {
				cout<< " Hello World" << b << " " << a<<endl;
			}
			if(x==median) {
				if(b+d<=m){
					//cout<<d <<  "Hello if" << b;

					cout<<tno<<" "<<(a+c)<<"/"<<(b+d)<<'\n';
					flag=true;	
					break;
				}
				/*long double min=(long double)abs(x-(long double)a/b);
				if(min<(long double)abs(x-(long double)c/d)) {
					cout<<tno<<" "<<a<<"/"<<b<<'\n';
					flag=true;
					break;
				}
				else {
					cout<<tno<<" "<<c<<"/"<<d<<'\n';
					flag=true;
					break;
				}*/
				else if(d>b) {
					//cout<<d <<  "hello else if" << b;
					cout<<tno<<" "<<a<<"/"<<b<<'\n';
					flag=true;
					break;
				}
				else {
					//cout<<d <<  "hello else " << b;

					cout<<tno<<" "<<c<<"/"<<d<<'\n';
					flag=true;
					break;
				}
			}	
			else if(x>median) {
				a=a+c;
				b=b+d;
			}
			else{
				c=a+c;
				d=b+d;
			}
		}
		if(!flag){
			if(b>m)
			{
				//cout<<b << " "<< " b greater "<<d;
				cout<<tno<<" "<<c<<"/"<<d<<'\n';
			}
			else
			{
				//cout<<b << " " << " b smaller " << d;
				cout<<tno<<" "<<a<<"/"<<b<<'\n';		
			}
		}

	}	
	
}
