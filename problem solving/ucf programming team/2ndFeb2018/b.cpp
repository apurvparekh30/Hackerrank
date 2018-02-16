#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;cin>>n;
	int total=0;
	int count=0;
	for(int i=0;i<n;i++){
		int no;
		cin>>no;
		if(no!=-1){
			total=total+no;
			count++;
		}
	}
	cout<<(double)total/count<<endl;
}