#include <bits/stdc++.h>

using namespace std;

vector <int> missingNumbers(vector <int> arr, vector <int> brr) {
    // Complete this function
    map <int,int> ma,mb;
    for(int i=0;i<arr.size();i++){
        ma[arr[i]]++;
    }
    for(int i=0;i<brr.size();i++){
        mb[brr[i]]++;
    }

    std::vector<int> v;
    for (auto it = mb.begin(); it != mb.end(); ++it) {
        if(it->second > ma[it->first]){
            v.push_back(it->first);
        }
    }

    return v;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int arr_i = 0; arr_i < n; arr_i++){
       cin >> arr[arr_i];
    }
    int m;
    cin >> m;
    vector<int> brr(m);
    for(int brr_i = 0; brr_i < m; brr_i++){
       cin >> brr[brr_i];
    }
    vector <int> result = missingNumbers(arr, brr);
    for (ssize_t i = 0; i < result.size(); i++) {
        cout << result[i] << (i != result.size() - 1 ? " " : "");
    }
    cout << endl;


    return 0;
}
