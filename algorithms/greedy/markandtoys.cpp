#include <bits/stdc++.h>

using namespace std;

int maximumToys(vector <int> prices, int k) {
    // Complete this function
    sort(prices.begin(),prices.end());
    int i=0;
    int count=0;
    while(k>0 && i<prices.size()){
        k=k-prices[i];
        count++;
        i++;
    }
    if(k<0){
        count--;
    }
    return count;
}

int main() {
    int n;
    int k;
    cin >> n >> k;
    vector<int> prices(n);
    for(int prices_i = 0; prices_i < n; prices_i++){
       cin >> prices[prices_i];
    }
    int result = maximumToys(prices, k);
    cout << result << endl;
    return 0;
}
