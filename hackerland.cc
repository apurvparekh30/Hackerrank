#include <bits/stdc++.h>

using namespace std;

class Compare
{
public:
    bool operator() (int p1, int p2)
    {
        if(p2<p1)
        	return true;
        return false;
    }

};

int main() {

	priority_queue <int,std::vector<int>, Compare >pq;

	int n,k;

	scanf("%d %d",&n,&k);

	for (int i = 0; i < n; ++i)
	{
		int xval;
		scanf("%d",&xval);
		pq.push(xval);
	}

	/*int x;
	ifstream inFile;

	inFile.open("input.txt");
	while (inFile >> x) {
		pq.push(x);
    }
	inFile.close();*/

	vector <int> v;
	while(!pq.empty()) {
		v.push_back(pq.top());
		pq.pop();
	}
	int count = 0;
	for(int i = 0;i<n;) {
		long range = 0;
		while(range <= k && i < n) {
			range = range + (v[i+1] - v[i]);
			i++;
		}
		count++;
		range = 0;
		i = i - 1;
		while(range <= k && i < n) {
			range = range + (v[i+1] - v[i]);
			i++;
		}
	}

	printf("%d",count);
	return 0;
}