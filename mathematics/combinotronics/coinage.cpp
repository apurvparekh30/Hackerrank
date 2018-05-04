#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	int n,a,b,c,d;

	cin>>t;
	while(t--){
		int count=0;
		cin>>n>>a>>b>>c>>d;
		for(int i=0;i<=b && (2*i)<=n;i++){
			for(int j=0;j<=c&&(5*j)<=n;j++){
				for(int k=0;k<=d&&(10*k)<=n;k++){
                    int total = (i*2)+(j*5)+(k*10);
					if( total >= (n-a) && total<=n)
						count++;
				}
			}
		}
		cout<<count<<endl;
	}
	return 0;
}