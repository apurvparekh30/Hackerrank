#include <bits/stdc++.h>

using namespace std;


int main(){
	int t;
	cin>>t;

	while(t--){
		int n;
		cin>>n;
		vector<int> v(n);
		for(int i=0;i<n;i++){
			cin>>v[i];
		}

		int ub = *min_element(v.begin(),v.end());
		int sum;
		int m=INT_MAX;
		for(int i=ub-4;i<=ub;i++){
			sum=0;
			for(int j=0;j<n;j++){
				int no=v[j]-i;
				sum=sum+(no/5)+((no%5)/2)+(((no%5)%2)/1);
			}
			m=min(m,sum);
		}

		cout<<m<<endl;
	}
	return 0;
}