#include <bits/stdc++.h>
using namespace std;

bool isPrime(int no){
	int j=(int)sqrt(no);
	for(int i=2;i<=j;i++){
		if(no%i==0){
			return false;
		}
	}
	return true;
}

bool getResult(int no,map<int,bool> mymap){
	if(no==1){
		return true;
	}
	if(mymap[no]){
		return false;
	}
	mymap[no]=true;
	int sum=0;
	while(no!=0){
		int rem=no%10;
		sum=sum+(rem*rem);
		no=no/10;
	}
	return getResult(sum,mymap);
}

int main(){
	int p;
	cin>>p;
	while(p--){
		int k;
		cin>>k;
		int no;
		cin>>no;
		if(no==1){
			cout<<k<<" "<<no<<" "<<"NO\n";
			continue;
		}
		if(isPrime(no)){
			map<int,bool> mymap;
			if(getResult(no,mymap)){
				cout<<k<<" "<<no<<" "<<"YES\n";
			}
			else{
				cout<<k<<" "<<no<<" "<<"NO\n";
			}
		}
		else{
			cout<<k<<" "<<no<<" "<<"NO\n";
		}
	}
	return 0;
}