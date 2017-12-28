#include <bits/stdc++.h>

using namespace std;

int main() {

	long g;
	ifstream inFile;
    inFile.open("input.txt");
    inFile>>g;
	//scanf("%ld",&g);
	while(g--){
		long m,n,x;
		inFile >>n>>m>>x;
		//scanf("%ld %ld %ld",&n,&m,&x);
		vector <long> st1;
		vector <long> st2;
		stack <long> t;

		for(long i=0;i<n;i++) {
			long temp;
			inFile>>temp;
			//scanf("%ld",&temp);
			st1.push_back(temp);
		}

		for(long i=0;i<m;i++) {
			long temp;
			inFile>>temp;
			//scanf("%ld",&temp);
			st2.push_back(temp);
		}

		long sum = 0;
		long i=0;
		long count=0;
		while(i<n && sum + st1[i]<=x) {
			sum+=st1[i];
			t.push(st1[i]);
			i++;
		}
		count = i;
		long j = i;
		i = 0;
		while(i<m){
			sum=sum+st2[i];
			i++;
			while(sum > x && !t.empty()) {
				sum=sum-t.top();
				t.pop();
				j--;
			}
			if(sum <= x && count < j+i) {
				count = j+i;
			}
			
			
		}
		/*ofstream outFile;
		outFile.open("output.txt");
		outFile<<count;*/
		printf("%ld\n", count);
	}
	



	return 0;
}