#include <bits/stdc++.h>
#define boost ios::sync_with_stdio(false);cin.tie(NULL);

using namespace std;

bool mycompare(pair<int,int> a,pair<int,int> b) {
    double f1=abs(sqrt(2) * max(a.first,a.second));
    double f2=abs(sqrt(2) * max(b.first,b.second));
    return f1<f2;
}

int main() {
    boost;
    int n,q;
    cin>>n>>q;
    vector<pair<int,int>> houses(n+1);
    for(int i=1;i<=n;i++) {
        int x,y;
        cin>>x>>y;
        houses[i]=make_pair(x,y);
    }
    for(int i=0;i<q;i++) {
        int l,m;
        cin>>l>>m;
        vector<pair<int,int>> range;
        for(int j=l;j<=m;j++) {
            range.push_back(houses[j]);
        }
        sort(range.begin(),range.end(),mycompare);
        pair<int,int> x=*range.begin();
        pair<int,int> y=*(range.end()-1);
        int result=max(abs(x.first-y.first), abs(x.second-y.second));
        x=*(range.begin()+1);
        result=min(result,max(abs(x.first-y.first), abs(x.second-y.second)));
        x=*range.begin();
        y=*(range.end()-2);
        result=min(result,max(abs(x.first-y.first), abs(x.second-y.second)));
        cout<<result<<'\n';
    }
    
    return 0;
}
