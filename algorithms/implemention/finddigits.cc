#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	int t;
    int x;
    cin>>x;
    while(x--){
        cin>>n;

        t = n;
        int count = 0;

        while (t>0){
            int rem = t%10;
            if( rem!=0 && n % rem == 0)
                count++;
            t=t/10;
        }
        cout<<count<<endl;
    }
	
	return 0;
}