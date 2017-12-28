#include <bits/stdc++.h> 

using namespace std;




int getParent(int i,int parent[]){
	while(i!=parent[i]){
		i = parent[i];	
	}
	return i;
}

void setParent(int g,int b,int parent[]) {
	int gp = getParent(g,parent);
	int bp = getParent(b,parent);
	if(gp > bp){
		parent[bp] = gp;
	}
	else {
		parent[gp] = bp;
	}
}

int main() {

	int n;
	cin >> n;


	int parent[2*n+1];
	for(int i=1;i<=2*n;i++) {
		parent[i]=i;
	}
	for(int i=0;i<n;i++) {
		int g,b;
		cin>>g>>b;
		setParent(g,b,parent);
	}

	int count[n*2+1];
	memset(count,0,sizeof(count));
	for(int i=1;i<=n*2;i++) {
		int p = getParent(i,parent);
		parent[i] = p;
		count[p]++;
	}
	int max = 0;
	int min = INT_MAX;
	for(int i=1;i<=n*2;i++){
		if(count[i] > max) {
			max = count[i];
		}
		if(count[i]<min && count[i]>=2)
		{
			min = count[i];
		}
	} 
	cout<<min<<" "<<max;
	return 0;
}