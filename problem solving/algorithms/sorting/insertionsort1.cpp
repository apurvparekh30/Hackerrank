
#include <bits/stdc++.h>

using namespace std;

void insertionSort1(int n, vector <int> arr) {
    // Complete this function
	int temp=arr[n-1];
	int i=n-2;
	while(arr[i]>temp) {
		arr[i+1]=arr[i];
		i--;
		for(int j=0;j<n;j++){
			cout<< arr[j] << " ";
		}
		cout<<endl;
	}
	arr[i+1]=temp;
	for(int j=0;j<n;j++){
		cout<< arr[j] << " ";
	}
	cout<<endl;

}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int arr_i = 0; arr_i < n; arr_i++){
       cin >> arr[arr_i];
    }
    insertionSort1(n, arr);
    return 0;
}
