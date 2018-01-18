#include <bits/stdc++.h>

using namespace std;

long stockmax(vector <int> prices) {
    // Complete this function
    int localMax=0;
    long profit=0;
    
    for(int i=prices.size()-1; i>=0;i--){
        if(localMax <= prices[i]) {
            localMax=prices[i];
        }
        profit=profit+(localMax-prices[i]);
    }
    return profit;
}

int main() {
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        vector<int> prices(n);
        for(int prices_i = 0; prices_i < n; prices_i++){
           cin >> prices[prices_i];
        }
        long result = stockmax(prices);
        cout << result << endl;
    }
    return 0;
}