#include <bits/stdc++.h>

using namespace std;

class Compare
{
public:
    bool operator() (pair<long,long> p1, pair<long,long> p2)
    {
        if(p2.second < p1.second)
        	return true;
        return false;
    }

};

int main() {

	long n;
	scanf("%ld",&n);
	priority_queue <pair<long,long>,std::vector<pair<long,long>>, Compare >pq;
	for(long i=0;i<n;i++) {
		long p;
		scanf("%ld",&p);
		long q;
		scanf("%ld",&q);
		pair <long,long> t = make_pair<long,long>(i+1,p+q);
		pq.push(t);
	}

	while(!pq.empty()) {
		pair<long,long> t = pq.top();
		pq.pop();
		printf("%ld ",t.first);
	}
	return 0;
}
