#include <bits/stdc++.h>

using namespace std;

void array_left_rotation(vector<int> a, int n, int k) {
     for(int i = 0; i < n;i++) {
        int temp = i + k;
        if(temp>=n){
            temp = temp - n;
        }
        cout << a[temp] << " ";
     }
}

int main(){
    int n;
    int k;
    cin >> n >> k;
    vector<int> a(n);
    for(int a_i = 0;a_i < n;a_i++){
        cin >> a[a_i];
    }
    array_left_rotation(a, n, k);
   
    cout << endl;
    return 0;
}
