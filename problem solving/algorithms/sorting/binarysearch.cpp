#include <bits/stdc++.h>
using namespace std;

bool binarySearch(vector<int> v,int start,int end,int key){
	if(start<end){			
		int mid=(start+end)/2;
		if(v[mid]==key){
			return true;
		}
		if(key<v[mid])
			return binarySearch(v,start,mid-1,key);
		else
			return binarySearch(v,mid+1,end,key);
	}
	return false;
}


int main() {
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++){
		v[i]=rand()%20+1;
	}
	cout<< "Elements are : " <<endl;
	for(int i=0;i<n;i++) {
		cout<< " "<<v[i];
	}
	cout<<endl;
	int key;
	cout<< " Key to search :" ;
	cin>>key;
	sort(v.begin(),v.end());
	int start=0,end=n-1;
	if(binarySearch(v,start,end,key)){
		cout<< " Found " << endl;
	}
	else {
		cout<< " Not Found " <<endl;
	}
	
}
