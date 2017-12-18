#include <bits/stdc++.h>

using namespace std;

int main() {
	long n,k;
	
	scanf("%ld %ld",&n,&k);
	int arr[k];
	memset(arr,0,sizeof(arr));
	priority_queue<long> pq;

	for(long i=0;i<n;i++) {
		long p;
		scanf("%ld",&p);
		pq.push(p);
	}
	long sum = 0;
	
	for(long i=0,j=0;i<n;i++,j++) {
		if(j == k) {
			j = 0;
		}
		int p = pq.top();
		pq.pop();
		sum=sum+(arr[j] + 1) * p;
		arr[j]++; 
	}	
	printf("%ld",sum);
	//printf("\n");
	return 0;
}
