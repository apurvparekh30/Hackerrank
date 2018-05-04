#include <bits/stdc++.h>

using namespace std;

int getTotalX(vector <int> a, vector <int> b) {
    // Complete this function
    int min = *min_element(b.begin(),b.end());
    int i = *max_element(a.begin(),a.end());
    int count = 0;
    for(;i<=min;i++){
        bool flag = true;
        for(int j=0;j<a.size();j++){
            if(i % a[j] != 0){
                flag = false;
                break;
            }
        }
        if(flag == false)
            continue;
        for(int j=0;j<b.size();j++) {
            if(b[j] % i != 0){
                flag =false;
                break;
            }
        }
        if(flag)
            count++;
        else
            continue;
    }
    return count;
}

int main() {
    int n;
    int m;
    cin >> n >> m;
    vector<int> a(n);
    for(int a_i = 0; a_i < n; a_i++){
       cin >> a[a_i];
    }
    vector<int> b(m);
    for(int b_i = 0; b_i < m; b_i++){
       cin >> b[b_i];
    }
    int total = getTotalX(a, b);
    cout << total << endl;
    return 0;
}
