#include <bits/stdc++.h>

using namespace std;

string twoArrays(int k, vector <int> A, vector <int> B) {
    // Complete this function
    int n=A.size();
    sort(A.begin(),A.end(),[](int a,int b){return a<b;});
    sort(B.begin(),B.end(),[](int a,int b){return a>b;});
    for(int i=0;i<n;i++){
        if(A[i]+B[i]<k){
            return "NO";
        }
    }
    return "YES";
}

int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        int n;
        int k;
        cin >> n >> k;
        vector<int> A(n);
        for(int A_i = 0; A_i < n; A_i++){
           cin >> A[A_i];
        }
        vector<int> B(n);
        for(int B_i = 0; B_i < n; B_i++){
           cin >> B[B_i];
        }
        string result = twoArrays(k, A, B);
        cout << result << endl;
    }
    return 0;
}
