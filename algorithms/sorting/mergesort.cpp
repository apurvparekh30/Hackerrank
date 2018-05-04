#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &v,int start,int mid,int end) {
	vector<int> v1,v2;
	for(int i=start;i<=mid;i++){
		v1.push_back(v[i]);
	}
	for(int i=mid+1;i<=end;i++){
		v2.push_back(v[i]);
	}

	int n1,n2;

	n1=v1.size();
	n2=v2.size();

	int i=0,j=0,k=start;
	while(i<n1 && j<n2){
		if(v1[i]<v2[j]){
			v[k]=v1[i];
			i++;
		}
		else{
			v[k]=v2[j];
			j++;
		}
		k++;
	}

	while(i<n1){
		v[k]=v1[i];
		i++;
		k++;
	}
	while(j<n2){
		v[k]=v2[j];
		j++;
		k++;
	}
}

void mergesort(vector<int>& v,int start,int end){
	if(start<end){
		int mid=(start+end)/2;
		mergesort(v,start,mid);
		mergesort(v,mid+1,end);
		merge(v,start,mid,end);
	}
}
int main() {
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++){
		v[i]=rand()%10+1;
	}
	int start=0;
	int end=n-1;
	cout<< "Before : ";
	for(int i=0;i<n;i++){
		cout<< " "<<v[i];
	}
	cout<<endl;
	mergesort(v,start,end);
	cout<< "After";
	for(int i=0;i<n;i++){
		cout<< " "<<v[i];
	}
	cout<<endl;
	return 0;
}