#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		cout<<"COMPANY "<<i<<endl;
		unordered_map<string,string> parent;
		unordered_map<string,int> sale;
		int n;
		cin>>n;
		for(int j=0;j<n;j++){
			string op;
			cin>>op;
			if(op=="ADD"){
				string p;
				cin>>p;
				string emp;
				cin>>emp;
				parent[emp]=p;
			}
			else if(op=="SALE") {
				string emp;
				cin>>emp;
				int salecount;
				cin>>salecount;
				while(emp!="ROOT"){
					sale[emp]+=salecount;
					emp=parent[emp];
				}
			}
			else{
				string emp;
				cin>>emp;
				cout<<sale[emp]<<endl;
			}

		}
	}
}