#include <bits/stdc++.h>
using namespace std;
void swap(int *a,int *b){
	int t=*a;
	*a=*b;
	*b=t;
}
int partition(vector<int>& v,int low,int high){
	int pivot=v[high];
	int i=low-1;
	for(int j=low;j<high;j++){
		if(v[j]<pivot){
			i++;
			swap(&v[i],&v[j]);
		}
	}
	swap(&v[i+1],&v[high]);
	return i+1;
}
void quicksort(vector<int>& v,int low,int high){
	if(low<high){
		int p=partition(v,low,high);
		quicksort(v,low,p-1);
		quicksort(v,p+1,high);
	}
}
int main() {
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	quicksort(v,0,n-1);
	for(int i=0;i<n;i++){
		cout<<v[i]<<" ";
	}
}