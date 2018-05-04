include <bits/stdc++.h>
#define boost ios::sync_with_stdio(false);cin.tie(NULL);

using namespace std;

int getSubSequence(vector<int> v,int n) {
	for(int i=1;i<n;i++){
		v[i]=max(v[i],max(v[i]+v[i-1],v[i-1]));
	}
	return v[n-1];
	/*int sum=max_element(v.begin(),v.end);
	if(sum<0)
		return sum;
	sum=0;
	for(auto i:v){
		if(i>0)		
			sum+=i;
	}
	return sum;*/
}

int getSubArray(vector<int> v,int n) {
	int sum=v[0];
	int temp=v[0];
	for(int i=1;i<n;i++) {
		temp=max(v[i],temp+v[i]);
		sum=max(sum,temp);
	}
	return sum;
}

int main() {
	boost;
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		vector<int> v(n);
		for(int i=0;i<n;i++) {
			cin>>v[i];
		}
		int res1,res2;
		res1=getSubArray(v,n);
		res2=getSubSequence(v,n);
		cout<<res1<<" " << res2<<'\n';
	}
	return 0;
}
