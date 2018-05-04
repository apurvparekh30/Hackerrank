#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &v,int start,int mid,int end) {
	vector<int> a,b;
	for(int i=start;i<=mid;i++) {
		a.push_back(v[i]);
	}
	for(int i=mid+1;i<=end;i++) {
		b.push_back(v[i]);
	}
	int n1= a.size();
	int n2= b.size();
	int i=0;
	int j=0;
	int k=start;
	while(i<n1 && j<n2){
		if(a[i]<b[j]) {
			v[k]=a[i];
			i+=1;
		}
		else {
			v[k]=b[j];
			j+=1;
		}
		k+=1;
	}
	while(i<n1) {
		v[k]=a[i];
		k+=1;
		i+=1;
	}
	while(j<n2) {
		v[k]=b[j];
		k+=1;
		j+=1;
	}
}

void mergesort(vector<int> &v,int start,int end) {
	if(start<end) {
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
	for(int i=0;i<n;i++) {
		v[i]=rand()%30+1;
	}
	cout<< " Before : " <<endl;
	for(int i=0;i<n;i++) {
		cout<< " "<<v[i];
	}
	cout<<endl;
	int start=0,end=n-1;
	mergesort(v,start,end);
	cout<< " After : " <<endl;
	for(int i=0;i<n;i++) {
		cout<< " "<<v[i];
	}
	cout<<endl;
	return 0;
}
