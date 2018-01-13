#include <bits/stdc++.h>

using namespace std;

int getAbsDiff(vector<long> v) {
    long min=LONG_MAX;
    for(int i=1;i<v.size();i++) {
    	if(min>v[i]-v[i-1]){
    		min=v[i]-v[i-1];
    		if(min==0){
    			return 0;
    		}
    	}
    }
	return min;
}

int main() {
	int n;
	cin>>n;
	vector<long> v(n);
	for(int i=0;i<n;i++){
		cin>>v[i];
	}

	sort(v.begin(),v.end());
    
	cout<<getAbsDiff(v);
	return 0;
}