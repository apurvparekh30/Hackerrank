#include <bits/stdc++.h>
using namespace std;

int getTotal(int x,int p,int no){
	if(pow(no,p)<x){
		return getTotal(x,p,no+1) + getTotal(x-pow(no,p),p,no+1);
	}
	else if(pow(no,p)==x){
		return 1;
	}
	else {
		return 0;
	}
}

int main(){
	int x,n;
	cin>>x>>n;
	cout<<getTotal(x,n,1);
	return 0;
}