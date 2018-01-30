#include <bits/stdc++.h>
#define mod 1000000007

using namespace std;
vector<int> v(100001);

int getResult(int n){
	if(n<0) return 0;
	if(v[n]!=0){
		return v[n];
	}
    //v[n]=getResult(n-1)+getResult(n-2)+getResult(n-3);
	v[n]=(getResult(n-1)%mod)+(getResult(n-2)%mod)+(getResult(n-3)%mod);
    return v[n];
}
int main(){
    int s;
    cin >> s;
    for(int a0 = 0; a0 < s; a0++){
        int n;
        cin >> n;
        v[0]=v[1]=1;
        cout<<getResult(n)<<endl;
    }
    return 0;
}
