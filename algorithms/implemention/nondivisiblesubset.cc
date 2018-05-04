#include <bits/stdc++.h>

using namespace std;

int main() {

	int n;
	int k;
	cin>>n;
	cin>>k;
	map<int,int> mymap;
	for(int i=0;i<n;i++){
		long no;
		cin>>no;
		mymap[no%k]++;
	}
	int count = 0;
	vector <int> v(k+1);
	for(map<int,int>::iterator it = mymap.begin(); it!= mymap.end();it++){
		if(it->first == 0 || (it->first == (k/2) && k%2 == 0)){
			count ++;
			continue;
		}
		if(!v[it->first] && !v[k-it->first])
		{
			int temp = max(it->second,mymap[k-it->first]);
			count = count + temp;
			v[it->first] = 1;
			v[k-it->first] = 1;
		}
	}
	cout << count;
	return 0;
}	