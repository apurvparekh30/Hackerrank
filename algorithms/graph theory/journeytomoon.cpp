#include <bits/stdc++.h>

using namespace std;

long dfs(int i,bool v[], vector<int> gv[]){
	v[i]=true;
	vector<int>::iterator it;
	long count = 1;
	for(it=gv[i].begin();it!=gv[i].end();it++){
		if(!v[*it]){
			count = count + dfs(*it,v,gv);
		}
	}

	return count;
}

long connectedComponents(vector<int> gv[],int n) {
	bool v[n];
	memset(v,false,sizeof(v));
	long result=0;
	vector<long> connCount(n);
	for(int i=0;i<n;i++){
		if(!v[i]){
			connCount[i] = dfs(i,v,gv);
		}
	}

	result=0;
	long sum=0;

	for(long size:connCount) {
		result=result+(sum *size);
		sum = sum + size;
	} 
	return result;
}


int main() {
	int n,p;
	cin>>n>>p;
	vector<int> gv[n];
	for(int i=0;i<p;i++){
		int a,b;
		cin>>a>>b;
		gv[a].push_back(b);
		gv[b].push_back(a);
	}
	cout<<connectedComponents(gv,n);
	return 0;
}