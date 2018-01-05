#include <bits/stdc++.h>

using namespace std;

int main() {

	int n;
	long k;

	cin>>n>>k;

	std::priority_queue<long, std::vector<long>, std::greater<long> > pq;
	for (int i = 0; i < n; ++i)
	{
		long no;
		cin>>no;
		pq.push(no);
	}

	std::vector<long> v;
	long a = pq.top();
	pq.pop();
	while(!pq.empty()){
		long b = pq.top();
		pq.pop();
		v.push_back(b-a);
		a = b;
	}	
	long count=0;
	long sum=0;
	for (long i = 0,j=0; i < v.size(); ++i)
	{
		sum = sum + v[i];
		while(sum >= k){
			if(sum == k){
				count++;
				break;
			}
			sum=sum-v[j];
			j++;
		}
	}

	cout<<count;
	return 0;
}