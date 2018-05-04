#include <bits/stdc++.h>
using namespace std;

string getResult(long p,long q){
	if(p<q){
		q=q-p;
		p=p+q;
		return (to_string(p)+"/"+to_string(q));
	}
	else{
		if(q==1){
			p++;
			return (to_string(q)+"/"+to_string(p));
		}
		else{
			if(q==2){
				return (to_string(q)+"/"+to_string(p));
			}
			
		}
	}
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int k;
		cin>>k;
		string s;
		cin>>s;
		long p,q;
		int l=0;
		int len=s.length();
		len=len-1;
		for(int i=0;s[i]!='/';i++){
			l++;
		}
		string left=s.substr(0,l);
		string right=s.substr(l+1,len-l);
		p=stol(left);
		q=stol(right);
		cout<<k<<" "<<getResult(p,q)<<endl;
	}
	return 0;
}