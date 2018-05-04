#include <bits/stdc++.h>

using namespace std;

vector < int > solve(vector < int > grades,int n){
    // Complete this function
    for(int i=0;i<n;i++){
        if(grades[i] >37) {
            int d = grades[i] / 5;
            if((5*(d+1)) - grades[i] < 3){
                grades[i] = 5 * (d+1);
            }
        }
    }
    return grades;
}

int main() {
    int n;
    cin >> n;
    vector<int> grades(n);
    for(int grades_i = 0; grades_i < n; grades_i++){
       cin >> grades[grades_i];
    }
    vector < int > result = solve(grades,n);
    for (ssize_t i = 0; i < result.size(); i++) {
        cout << result[i] << (i != result.size() - 1 ? "\n" : "");
    }
    cout << endl;
    

    return 0;
}
