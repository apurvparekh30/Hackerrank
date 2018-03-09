#include <bits/stdc++.h>
using namespace std;

bool compare(pair<long,long> a,pair<long,long> b) {
	if(a.first==b.first) {
		a.second<b.second;		
	}
	return a.first<b.first;
}
vector<pair<long,long> > get_free_longerval(vector< pair<long,long> > v,long n,long c) {
	vector<pair<long,long> > max_free_longerval;
	if(v[0].first>1){
		max_free_longerval.push_back(make_pair(1,v[0].first-1));	
	}
	if(v[n-1].second<c) {
		max_free_longerval.push_back(make_pair(v[n-1].second+1,c));
	}
	for(long i=0,j=i+1;i<n-1;i++,j++) {
		if(v[i].second<v[j].first) {
			max_free_longerval.push_back(make_pair(v[i].second+1,v[j].first-1));
		}	
	}
	return max_free_longerval;
}	

string getOverlapping(vector<pair<long,long> > v,long n,long k,long c) {
	bool flag=true;
	if(n==1)
		return "Good\n";
	for(long i=0,j=i+1;i<n-1 && j<n;i++,j++) {
		if(v[i].second>=v[j].first){
			if(k==0){
				return "Bad\n";
			}
			else {
				if(flag) {
					vector<pair<long,long> > maxlongerval=get_free_longerval(v,n,c);
					long isize=(v[i].second-v[i].first)+1;
					long jsize=(v[j].second-v[j].first)+1;
				
					for(vector<pair<long,long> > :: iterator k=maxlongerval.begin();k!=maxlongerval.end();k++) {
						long size=(k->second-k->first)+1;
						if(size>=isize){
							v.erase(v.begin()+i);
							flag=false;
							break;
						}
						if(size>=jsize) {
							v.erase(v.begin()+j);
							flag=false;	
							break;
						}
					}
					if(flag)
						return "Bad\n";	
					else {
						i=-1;
						j=i+1;
						n--;
					}
				}
				else {
					return "Bad\n";
				}	
			}
		}
	}
	return "Good\n";
}
int main() {
	long c,n,k;
	cin>>c>>n>>k;
	vector<pair<long,long> > v(n);
	for(long i=0;i<n;i++){
		long s,e;
		cin>>s>>e;
		v[i]=make_pair(s,e);
	}
	sort(v.begin(),v.end(),compare);
	cout<<getOverlapping(v,n,k,c);
	return 0;
}
