#include <bits/stdc++.h>
using namespace std;

int getResult(vector<int> v){
	int count=0;
	stack<int> st;
	st.push(v[0]);
	for(int i=1;i<v.size();i++){
		while(!st.empty()&&v[i]<st.top()){
			st.pop();
			count++;
		}
		if(v[i]>st.top()){
			st.push(v[i]);
		}
	}
	return count;
}

int main(){
	int p;
	cin>>p;
	while(p--){
		int k;
		cin>>k;
		vector<int> v(12);
		for(int i=0;i<12;i++){
			cin>>v[i];
		}
		cout<<k<<" "<<getResult(v)<<"\n";
	}
	return 0;
}