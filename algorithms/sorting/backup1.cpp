#include <bits/stdc++.h>
using namespace std;

bool compare(pair<long,long> a,pair<long,long> b) {
	if(a.first==b.first) {
		a.second<b.second;		
	}
	return a.first<b.first;
}

vector<long> get_free_interval(vector<pair<long,long> > v,long  n,long c) {
	vector<long> maxinterval;
	if(v[0].first>1) 
		maxinterval.push_back(v[0].first-1);	
	if(v[n-1].second<c)
		maxinterval.push_back(c-v[n-1].second);
	for(long i=0,j=i+1;i<n-1;i++,j++) {
		if(v[i].second<v[j].first) {
			maxinterval.push_back((v[j].first-v[i].second)-1);
		}
	}
	return maxinterval;
}	

string getOverlapping(vector<pair<long,long> > v,long n,long k,long c) {	
	bool flag=true;
	for(long i=0,j=i+1;i<n-1 && j<n;i++,j++) {
		if(v[j].first<=v[i].second){
			if(k==0){
				return "Bad\n";
			}
			else {
				if(flag) {
					vector<long> maxinterval=get_free_interval(v,n,c);
					int isize=(v[i].second-v[i].first)+1;
					int jsize=(v[j].second-v[j].first)+1;
					for(vector<long>::iterator size=maxinterval.begin();size!=maxinterval.end();size++) {
						if(*size>=jsize) {
							if(j!=n-1){
								if(v[j-1].second<v[j+1].first) {
									v[j]=make_pair(0,0);
									flag=false;
									break;
								}
							}
							else {
								v[j]=make_pair(0,0);
								flag=false;
								break;
							}
						}
						if(*size>=isize) {
							if(i!=0){
								if(v[i-1].second<v[i+1].first) {
									v[i]=make_pair(0,0);
									flag=false;
									break;
								}								
							}
							else {
								v[i]=make_pair(0,0);
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

