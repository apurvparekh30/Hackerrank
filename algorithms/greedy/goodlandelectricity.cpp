#include <bits/stdc++.h>

using namespace std;

int pylons(int k,vector<int> arr,vector<int> oneindex) {
    int n=arr.size();
    int i=-1;
    int count=0;
    while(i<n){
        i=min(i+k,n-1);
        i=oneindex[i];
        if(i==-1){
            return -1;
        }
        count++;
        i=i+k-1;
    }
    return count;
}

int main() {
    int n;
    int k;
    cin >> n >> k;
    vector<int> arr(n);
    vector<int> oneindex(n);
    int lastone=-1;
    for(int arr_i = 0; arr_i < n; arr_i++){
        cin >> arr[arr_i];
        if(arr[arr_i] == 1){
            oneindex[arr_i]=arr_i;
            lastone=arr_i;
        }
        else{
            if(arr_i-lastone>(2*k)-2){
                oneindex[arr_i]=-1;
            }
            else{
                oneindex[arr_i]=lastone;
            }
            
        }
    }
    int result = pylons(k,arr,oneindex);
    cout << result << endl;
    return 0;
}
    