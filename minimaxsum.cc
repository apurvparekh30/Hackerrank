#include <bits/stdc++.h>

using namespace std;

int main() {
    
    priority_queue <int> pq;
    for(int arr_i = 0; arr_i < 5; arr_i++){
    	int n;
       cin >> n;
       pq.push(n);
    }

    vector<int> v(5);
    int i=0;
    while(!pq.empty()){
    	v[i] = pq.top();
    	pq.pop();
    	i++;
    }

    long maxsum = (long)v[0]+v[1]+v[2]+v[3];
    long minsum = (long)v[1]+v[2]+v[3]+v[4];

    cout<<minsum << " "<<maxsum;
    return 0;
}