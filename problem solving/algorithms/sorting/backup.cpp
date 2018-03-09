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
	vector<pair<long,long> > maxlongerval=get_free_longerval(v,n,c);
	bool flag=true;
	for(long i=0,j=i+1;i<n-1;i++,j++) {
		if(v[j].first<=v[i].second){
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
							if(i!=0){
								if(v[i-1].second<v[i+1].first) {
									v[i].first=k->first;
									v[i].second=k->second;
									flag=false;
									break;
								}
							}
							else {
								v[i].first=k->first;
								v[i].second=k->second;
								flag=false;
								break;
							}
						}
						if(size>=jsize) {
							if(j!=n-1) {
								if(v[j-1].second<v[j+1].first) {
									v[j].first=k->first;
									v[j].second=k->second;
									flag=false;
									break;
								}
							}
							else {
								v[j].first=k->first;
								v[j].second=k->second;
								flag=false;
								break;
							}
						}
					}
					if(flag)
						return "Bad\n";	
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

