#include <bits/stdc++.h>

using namespace std;

int main() {

	long n,k;
	scanf("%ld %ld",&n,&k);
	priority_queue <long,std::vector<long>, std::greater<long>>pq;
	for(long i=0;i<n;i++) {
		long p;
		scanf("%ld",&p);
		pq.push(p);
	}

	vector<long> v;
	while(!pq.empty()) {
		v.push_back(pq.top());
		pq.pop();
	}

	/*for(long i = 0;i<n;i++) {
		printf("%4ld",v[i]);
	}*/
	/*printf("\nhello");*/
	long diff = k - 1;
	/*printf("\n%d",diff);*/
	long min = LONG_MAX;
	for(long i=0;i<n-diff;i++) {
		/*printf("\nhhh");*/
		//printf("\n%d",v[i]);
		long x = v[i];
		long y = v[i + diff];

		if(min > (y-x)) {
			min = (y-x);
		}
	}
	printf("%ld",min);
	return 0;
}
