#include <bits/stdc++.h>

using namespace std;

int examRush(vector <int> tm, int t) {
    // Complete this function
    sort(tm.begin(),tm.end());
    int i=0;
    while(t>0){
        t-=tm[i];
        i++;
    }
    if(t<0)
      i--;
    return i;
}

int main() {
    int n;
    int t;
    cin >> n >> t;
    vector<int> tm(n);
    for(int tm_i = 0; tm_i < n; tm_i++){
       cin >> tm[tm_i];
    }
    int result = examRush(tm, t);
    cout << result << endl;
    return 0;
}

