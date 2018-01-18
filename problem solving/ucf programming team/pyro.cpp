#include <bits/stdc++.h>

using namespace std;

int main(){
	vector<int> v;
	int no;
	while(1) {
		cin>>no;
		if(no==-1)
			break;
		v.push_back(no);
	}
	
	for(int i=0;i<v.size();i++){
		bitset<18> a(v[i]);
		int alt=0;
		for(int j=i+1;j<v.size();j++){
			bitset<18> b(v[j]);
			if(abs((int)a.count() - (int)b.count()) > 2){
				continue;
			}
			int diff=0;
			for(int k=0;k<18 && diff<=2;k++){
				if(a[k]!= b[k]) {
					diff++;
				}
			}
			if(diff <= 2){
				alt++;
			}

		}
		cout <<v[i]<<":"<<alt<<endl;
	}
	return 0;
}