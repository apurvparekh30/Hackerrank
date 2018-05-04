
#include <bits/stdc++.h>

using namespace std;

vector <int> quickSort(vector <int> arr) {
    // Complete this function
	int n=arr.size();
	int pivot=0;
	int i=n-1;
	for(int j=n-1;j>=0;j--) {
		if(arr[j]>arr[pivot]) {
			swap(arr[i],arr[j]);
			i--;
		}
	}
	swap(arr[i],arr[pivot]);
	return arr;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int arr_i = 0; arr_i < n; arr_i++){
       cin >> arr[arr_i];
    }
    vector <int> result = quickSort(arr);
    for (ssize_t i = 0; i < result.size(); i++) {
        cout << result[i] << (i != result.size() - 1 ? " " : "");
    }
    cout << endl;


    return 0;
}
