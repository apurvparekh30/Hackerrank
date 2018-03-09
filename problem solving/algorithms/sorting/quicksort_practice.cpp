#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &v,int start,int end) {
	int i=start-1;
	int j=start;
	int pivot=v[end];
	for(;j<end;j++){
		if(v[j]<pivot){
			i+=1;
			swap(v[i],v[j]);
		}
	}
	swap(v[i+1],v[end]);
	return i+1;

}
void quicksort(vector<int> &v,int start,int end) {
	if(start<end) {
		int p=partition(v,start,end);
		quicksort(v,start,p-1);
		quicksort(v,p+1,end);
	}
}

int main (){
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++){
		v[i]=rand()%30+1;
	}
	cout<< "Before :"<<endl;
	for(int i=0;i<n;i++){
		cout<<" "<<v[i];
	}
	cout<<endl;
	int start=0;
	int end=n-1;
	quicksort(v,start,end);
	cout<< "After :"<<endl;
	for(int i=0;i<n;i++){
		cout<<" "<<v[i];
	}
	cout<<endl;

	return 0;
}
