#include <bits/stdc++.h>

using namespace std;

int main() {

	vector<int> v;

	for(int i=0;i<5;i++) {
		v.push_back(5-i);
	}

	sort(v.begin(),v.end(),[](int a,int b){return a<b;});
	return 0;
}