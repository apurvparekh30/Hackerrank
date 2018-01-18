#include <bits/stdc++.h>
#define x 1000000007
using namespace std;

long long pow2(int y){
	long long res=1;
	for(int i=0;i<y;i++)
		res=res*2%x;
	return res;
}

int main(){
	int n;
	cin>>n;
	vector<int> v(n);
	int evenCount=0;
	int oddCount=0;
	for(int i=0;i<n;i++){
		cin>>v[i];
		if(v[i]%2==0){
			evenCount++;
		}
		else {
			oddCount++;
		}
	}
	long long total;
	if(oddCount == 0){
		total = pow2(evenCount)-1;
	}
	else {
		total = pow2(evenCount) *  pow2(oddCount-1) - 1;
	}
	total = total%x;
	cout<<total;
	return 0;
}