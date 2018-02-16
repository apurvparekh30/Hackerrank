#include <bits/stdc++.h>

using namespace std;


int main() {
    int n;
    cin >> n;
    set<int> a,b;
    map<int,int> am,bm;
    for(int i=0;i<n;i++){
    	int no;
    	cin>>no;
    	am[no]++;
    	a.insert(no);
    }
    for(int i=0;i<n;i++){
    	int no;
    	cin>>no;
    	bm[no]++;
    	b.insert(no);
    }
    int count=0;
    for(auto i=a.begin();i!=a.end();i++){
    	count+=min(am[*i],bm[*i]);
    }
    if(count==n){
    	cout<<count-1<<endl;
    }
    else{
    	cout<<count+1<<endl;
    }
    
    return 0;
}
