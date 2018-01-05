#include <bits/stdc++.h>

using namespace std;

string canConstruct(vector <int> v) {
    // Return "Yes" or "No" denoting whether you can construct the required number.
    long sum = 0;
    for(int i=0;i<v.size();i++){
    	long no = v[i];
    	while(no!=0){
    		sum = sum + no % 10;
    		no = no / 10;
    	}
    }
    if(sum % 3 == 0)
    	return "Yes";
    else 
    	return "No";
}

int main() {
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int a_i = 0; a_i < n; a_i++){
           cin >> a[a_i];
        }
        string result = canConstruct(a);
        cout << result << endl;
    }
    return 0;
}
