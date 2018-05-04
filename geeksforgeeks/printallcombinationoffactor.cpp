#include <bits/stdc++.h>
using namespace std;

void printFactors(set<vector<int>>& st, vector<int> v,int n){
	if(n==1)
		return;
	for(int i=2;i<n;i++){
		if(n%i==0){
			v.push_back(i);
			v.push_back(n/i);
			sort(v.begin(),v.end()); // to avoid duplicates like {2,8},{8,2}
			st.insert(v);
			v.pop_back();
			printFactors(st,v,n/i);
			v.pop_back();
		}
	}
}
int main(){
	int n;
	cin>>n;
	set<vector<int>>st;
	vector<int> s;
	printFactors(st,s,n);
	for(auto i=st.begin();i!=st.end();i++){
		for(auto j=i->begin();j!=i->end();j++){
			cout<<*j<<" ";
		}
		cout<<endl;
	}
	return 0;
}