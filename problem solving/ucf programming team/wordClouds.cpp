#include <bits/stdc++.h>

using namespace std;

struct cloud {
	int height;
	int width;
};

bool mycompare(cloud a,cloud b) {
	return a.height>b.height;
}

int main(){
	int n,c;
	cin>>n>>c;
	vector<cloud> v(n);
	map<int,int> m;

	for(int i=0;i<n;i++) {
		int w,h;
		cin>>w>>h;
		v[i].width = w;
		v[i].height = h;
	}	

	sort(v.begin(),v.end(),mycompare);
	int temp = n;
	int sum = 0;
	int tempwidth=0;
	while(temp){
		bool flag = false;
		tempwidth = 0;
		for(int i=0;i<n && temp;i++){
			if(tempwidth + v[i].width <= c && !m[i]) {
				if(!flag){
					sum = sum + v[i].height;
					flag = true;
				}
				tempwidth = tempwidth+v[i].width;
				m[i]=1;
				temp--;
			}
		}
	}

	cout<<sum;
	return 0;
}