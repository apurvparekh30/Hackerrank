#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin>>n;
	vector<string> v(n);
	priority_queue <string> pq;
	for(int i=0;i<n;i++){
		cin>>v[i];
		pq.push(v[i]);
	}

	if(v[0]==pq.top()){
		for(int i=0;i<n;i++){
			if(v[i]!=pq.top()){
				printf("NEITHER\n");
				return 0;
			}
			pq.pop();
		}
		printf("DECREASING\n");
	}
	else {
		for(int i=n-1;i>=0;i--){
			if(v[i]!=pq.top()){
				printf("NEITHER\n");
				return 0;
			}
			pq.pop();
		}
		printf("INCREASING\n");
	}
	return 0;
}