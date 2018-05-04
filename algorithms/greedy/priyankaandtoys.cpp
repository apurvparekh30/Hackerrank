#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end(),[](int a,int b){return a<b;});
    int result=0;
    for(int i=0;i<n;i=upper_bound(v.begin(),v.end(),v[i]+4)-v.begin()){
        result++;
    }
    cout<<result<<endl;
}
