#include <bits/stdc++.h>

using namespace std;
int main() {
	int q;
	ifstream inFile;
    inFile.open("input.txt");
    inFile>>q;
	//cin>>q;

	while(q--){
		int n;
		inFile>>n;
		//cin>>n;

		vector<vector<long>> v(n,vector<long>(n));
		priority_queue<long> ccap;
		long count = 0;
		for(int i=0;i<n;i++){
			count = 0;
			for(int j=0;j<n;j++){
				inFile>>v[i][j];
				//cin>>v[i][j];
				count = count + v[i][j];
			}
			ccap.push(count);
		}	

		count = 0;
		priority_queue<long> bt;
		for(int i=0;i<n;i++){
			count = 0;
			for(int j=0;j<n;j++){
				count = count + v[j][i];
			}
			bt.push(count);
		}
		bool flag = true;
		while(!ccap.empty()){
			long a = ccap.top();
			ccap.pop();
			long b = bt.top();
			bt.pop();

			if(a!=b){
				flag = false;
				break;
			}
		}
		if(flag)
			printf("Possible\n");
		else
			printf("Impossible\n");
	}
	return 0;
}