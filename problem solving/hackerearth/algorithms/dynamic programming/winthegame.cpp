#include <bits/stdc++.h>
using namespace std;

double getProb(double r,double g,double t){
	double ans=(r/t);
	if(g>2){
		ans+=(g/t)*(g-1)/(t-1)*getProb(r,g-2,t-2);
	}
	return ans;
}
int main(){
	int t; cin>>t;
	while(t--){
		double r,g; 
		cin>>r>>g;
		if(r==0){
			cout<<"1.000000\n";
			continue;
		}
		double t=r+g;
		double answer=getProb(r,g,t);
		printf("%lf\n",answer);
	}
	return 0;
}