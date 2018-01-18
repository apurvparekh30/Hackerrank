#include <bits/stdc++.h>

using namespace std;


int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int arr_i = 0;arr_i < n;arr_i++){
       cin >> arr[arr_i];
    }
    int p,nt,z;
    p = nt = z = 0;
    for(int i=0;i<n;i++){
    	if(arr[i] > 0){
    		p++;
    		continue;
    	}
    	if(arr[i] < 0){
    		nt++;
    		continue;
    	}
    	z++;
    }
    cout << fixed << (double)p/n <<endl;
    cout << fixed << (double)nt/n<<endl;
    cout << fixed << (double)z/n<<endl;
    return 0;
}
