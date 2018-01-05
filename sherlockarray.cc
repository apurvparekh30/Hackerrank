#include <bits/stdc++.h>

using namespace std;
int main() {

	ifstream inFile;
    inFile.open("input.txt");
	int t;
	//cin>>t;
	inFile>>t;

	while(t--){
		int n;
		//cin>>n;
		
    	inFile>>n;

		vector<long> v(n);
		//cin>>v[0];
		inFile>>v[0];
		if(n == 1){
    		cout<<"YES"<<endl;
    		continue;
    	}
		for(int i=1;i<n;i++){
			//cin>>v[i];
			inFile>>v[i];
			v[i] = v[i] + v[i-1];
		}
		bool flag = false;
		for(int i=1;i<n-1;i++){
			int a = v[i-1];
			int b = v[n-1];

			if(b - v[i] == a){
				flag = true;
				break;
			}
		}

		if(flag){
			cout<<"YES"<<endl;
		}
		else {
			cout<<"NO"<<endl;
		}
	}
	return 0;
}