#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &v,int low,int high) {
	int i=low-1;
	int pivot=v[high];
	for(int j=low;j<high;j++) {
		if(v[j]<pivot) {
			i++;
			swap(v[i],v[j]);
		}
	}
	swap(v[i+1],v[high]);
	return i+1;
}


void quicksort(vector<int> &v,int low,int high) {
	if(low<high) {
		int p=partition(v,low,high);
		quicksort(v,low,p-1);
		quicksort(v,p+1,high);
	}
}

int main() {
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++) {
		v[i]=rand()%15;
	}
	cout<< "Before Sorting : "<<endl;
	for(int i=0;i<n;i++) {
		cout<< " "<< v[i];
	}
	cout<<endl<<endl;
	int low=0,high=n-1;
	quicksort(v,low,high);
	cout<< "After Sorting : "<<endl;
	for(int i=0;i<n;i++) {
		cout<< " "<< v[i];
	}
	cout<<endl<<endl;

}
