#include <bits/stdc++.h>
using namespace std;
int main(){
	int p;
	cin>>p;
	while(p--){
		int k;
		cin>>k;
		vector<int> v(20);
		for(int i=0;i<20;i++){
			cin>>v[i];
		}
		int steps=0;
		for(int i=1;i<20;i++){
			int key=v[i];
			int j=i-1;
			while(j>=0&&v[j]>key){
				v[j+1]=v[j];
				steps++;
				j--;
			}
			v[j+1]=key;
		}	
		cout<<k<<" "<<steps<<"\n";
	}
	return 0;
}