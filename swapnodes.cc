#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int n;
	int t;
	int k;

    ifstream inFile;
    inFile.open("input.txt");
    inFile>>n;
	//cin>>n;

	vector <pair<int,int>> v(n+1);
	vector <int> d(n+1);
	d[1] = 1;


	for(int i=1;i<=n;i++) {
		int a,b;
		inFile>>a;
		inFile>>b;
		//cin>>a>>b;
		pair<int,int> p = make_pair(a,b);
		v[i] = p;
		if(a>=0)
			d[a] = d[i] + 1;
		if(b>=0)
			d[b] = d[i] + 1;
	}
	inFile>>t;
	//cin>>t;
	while(t--) {
		inFile>>k;
		//cin >>k;
		for(int j=1;j<=n;j++){
			if(d[j]%k == 0){
				pair<int,int> p = make_pair(v[j].second,v[j].first);
				v[j]=p;
			}
		}
		stack<int>st;
		st.push(1);
		int i;
		vector <pair<int,int>> bk = v;
		while(!st.empty()){
			i = st.top();
			if(v[i].first!=-1){
				st.push(v[i].first);
				v[i].first = -1;
				continue;
			}
			printf("%d ", i);
			st.pop();
			if(v[i].second!=-1){
				st.push(v[i].second);
				v[i].second = -1;
				continue;
			}
		}
		v = bk;
		printf("\n");
	}
	return 0;
}
