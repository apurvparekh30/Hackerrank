#include <bits/stdc++.h>

using namespace std;

int main() {
    int n,q;
    scanf("%d",&n);
    map<string,int> mymap;

    for(int i=0;i<n;i++) {
        string s;
        cin >>s;
        mymap[s]++;
    }

    scanf("%d",&q);
    for(int i=0;i<q;i++) {
        string s;
        cin >> s;
        printf("%d\n", mymap[s]);
    }
    return 0;
}
