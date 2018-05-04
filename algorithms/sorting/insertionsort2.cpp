
#include <bits/stdc++.h>

using namespace std;

void insertionSort(int n, vector <int> arr) {
     	for(int i=1;i<n;i++) {
		int temp=arr[i];
		int j=i-1;
		while(j>=0 && arr[j]>temp){
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=temp;
		for(int j=0;j<n;j++){
			cout<< arr[j] << " ";
		}
		cout<<endl;
	}
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int arr_i = 0; arr_i < n; arr_i++){
       cin >> arr[arr_i];
    }
    insertionSort(n, arr);
    return 0;
}

