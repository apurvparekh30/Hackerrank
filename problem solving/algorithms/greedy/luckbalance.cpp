#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,k;
	cin>>n>>k;
	vector<pair<int,int>> l(n);
	for(int i=0;i<n;i++){
		cin>>l[i].first;
		cin>>l[i].second;
	}
	sort(l.begin(),l.end(),[](pair<int,int> a,pair<int,int> b){return a.first>b.first;});
	int total_luck=0;
	for(pair<int,int> i:l){
		if(i.second==0){
			total_luck+=i.first;
		}
		else if(k){
			total_luck+=i.first;
			k--;
		}
		else{
			total_luck-=i.first;
		}
	}
	cout<<total_luck<<endl;
	return 0;
}