#include <bits/stdc++.h>

using namespace std;

long raceAgainstTime(int n,  vector <int> heights, vector <int> prices) {
    // Complete this function
    vector<long> d(n+1,10E9);
    d[0]=0;
    long currdist=0;
    for(int i=0;i<=n;i++){
        long currheight=heights[i];
        for(int j=i+1;j<=n ;j++){
            long newdist;
            if(j==n){
                newdist=currdist+(j-i);
            }
            else {
                newdist=currdist+abs(currheight-heights[j])+prices[j]+(j-i);
            }
            
            if(newdist < d[j]){
                d[j]=newdist;
            }
            if(heights[j]>currheight){
                break;
            }
        }
        currdist=d[i+1];
    }
    return d[n];
}

int main() {
    int n;
    cin >> n;
    vector<int> heights(n);
    cin>>heights[0];
    for(int heights_i = 1; heights_i <n; heights_i++){
       cin >> heights[heights_i];
    }
    vector<int> prices(n);
    for(int prices_i = 1; prices_i < n; prices_i++){
       cin >> prices[prices_i];
    }
    long result = raceAgainstTime(n,heights, prices);
    cout << result << endl;
    return 0;
}
