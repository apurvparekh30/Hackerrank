#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector< vector<int> > a(n,vector<int>(n));
    for(int a_i = 0;a_i < n;a_i++){
       for(int a_j = 0;a_j < n;a_j++){
          cin >> a[a_i][a_j];
       }
    }
    int x = 0;
    int y = 0;
    int t = n - 1;
    for (int i = 0; i < n; ++i)
    {
    	/* code */
    	x = x + a[i][i];
    	y = y + a[i][t-i];
    }
    cout << abs(x-y);
    
    return 0;
}
