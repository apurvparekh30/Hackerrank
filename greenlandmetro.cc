#include <bits/stdc++.h>

using namespace std;

bool myCompare(pair<long,long> p1, pair<long,long> p2){
	return (p1.first < p2.first);
}

int main() {

	long n,m,k;
	ifstream inFile;
    inFile.open("input.txt");
    inFile>>n>>m>>k;
	//cin>>n>>m>>k;
	long long count = (long long)n * (long long )m;
	long long deduct = 0;
	vector<vector<pair<long,long>>> v(n+1);
	while(k--){
		long r,c1,c2;
		inFile>>r>>c1>>c2;
		//cin>>r>>c1>>c2;
		v[r].push_back(make_pair(c1,c2));
		//cout<<v[r][0].first<<endl;
	}

	for(long i=1;i<=n;i++) {
		if(v[i].size() == 0)
			continue;
		sort(v[i].begin(),v[i].end(),myCompare);
		long p = 0;
		for(long j=0;j<v[i].size();j++){
			if(v[i][j].first <= p){
				long temp = v[i][j].second - p;
				if(temp > 0){
					deduct = deduct + temp;
				}
			}
			else if(v[i][j].first > p){
				deduct = deduct + (v[i][j].second - v[i][j].first) + 1;
			}
			p = max(p,v[i][j].second);
		}
	}

	cout<<count-deduct;
	return 0;
}