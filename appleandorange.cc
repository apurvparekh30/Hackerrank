    #include <map>
    #include <bits/stdc++.h>

    using namespace std;

    int main(){
        int s;
        int t;
        cin >> s >> t;
        int a;
        int b;
        cin >> a >> b;
        int m;
        int n;
        cin >> m >> n;
        int d;
        int count = 0;
        for(int apple_i = 0;apple_i < m;apple_i++){
           cin>>d;
           if(a+d >= s && a+d<=t){
                count++;
           }
        }
        cout<<count<<endl;
        count=0;
        for(int orange_i = 0;orange_i < n;orange_i++){
           cin>>d;
           if(b+d >= s && b+d<=t){
                count++;
           }
        }
        cout<<count;
        return 0;
    }
