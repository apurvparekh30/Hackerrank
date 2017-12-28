#include <bits/stdc++.h>

using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    long n;
    long k;

    cin>>n;
    cin>>k;

    priority_queue <long, std::vector<long>, std::greater<long>> pq;

    for (long i = 0; i < n; ++i)
    {
    	/* code */
    	long no;
    	cin>>no;
    	pq.push(no);
    }
    if(pq.top() >= k) {
    	cout<<"0";
    	return 0;
    }

    long count = 0;
    long sweet=0;
    while(pq.size() >= 2) {
    	if(pq.top() >= k)
    		break;
    	count ++;
    	long no1 = pq.top();
    	pq.pop();
    	long no2 = pq.top();
    	pq.pop();

    	sweet = no1 + (2 * no2);
    	pq.push(sweet);
    }	

    if(sweet < k)
    	cout<<"-1";
    else
    cout<<count;

    return 0;
}
