#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> b(n);
		for(int i=0;i<n;i++){
			cin>>b[i];
		}
		int prev_i,prev_1;
		prev_1=0;
		prev_i=0;

		int new_prev_i;
		int new_prev_1;

		for(int i=1;i<n;i++){
			new_prev_i=max(prev_i+abs(b[i]-b[i-1]),prev_1+(b[i]-1));
			new_prev_1=max(prev_i+abs(1-b[i-1]),prev_1);
			prev_1=new_prev_1;
			prev_i=new_prev_i;
		}
		cout<<max(prev_i,prev_1)<<endl;
	}
	return 0;
}