#include <bits/stdc++.h>
using namespace std;

bool compare(int a,int b) {
	return a>b;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int> v;
	for(int i=0;i<10;i++) {
		v.push_back((rand()%10)+1);
	}
	cout<<"Before Heap : \n";
	for(auto i:v)
		cout<<i<<" ";
	cout<<"\n";
	make_heap(v.begin(),v.end(),compare);
	cout<<"After Heap: \n";
	for(auto i:v)
		cout<<i<< " ";
	cout<<"\n";
	//cout<< " end element " << *(v.end()-1)<<endl;
	auto i=find(v.begin(),v.end(),4);
	cout<< " i +1 th elelment : " <<*(i+1)<<"\n";
	swap(*i,*(v.end()-1));
	v.erase(v.end()-1);
	cout<<"After removal : \n";
	for(auto i:v) 
		cout<<i<<" ";
	cout<<"\n";
	make_heap(i,v.end(),compare);
	cout<<"After ramoval and heapify : \n";
	for(auto i:v)
		cout<<i<<" ";
	cout<<"\n";
	return 0; 
}
