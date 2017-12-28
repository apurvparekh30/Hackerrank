#include <bits/stdc++.h>

using namespace std;
int main() {	
	int n,q;
	cin >>n>>q;
	
	vector<int> v;

	vector<stack<int>> vs(q+1);
	vector<stack<int>> vb(q+1);
	int i=0;
	int j=2;
	while(i < q) {
		bool flag = true;
		for(int k=2;k<=j/2;k++){
			if(j%k == 0){
				flag = false;
				break;
			}
		}
		if(flag) {
			v.push_back(j);
			i++;
			
		}
		j++;
	}

	for (int i = 0; i < n; ++i)
	{
		int no;
		cin>>no;
		vs[0].push(no);
	}

	for(int i=1;i<=q;i++) {
		int stackIndex = i - 1;
		while(!vs[stackIndex].empty()) {
			int no = vs[stackIndex].top();
			vs[stackIndex].pop();
			if(no%v[i-1] == 0){
				vb[i].push(no);
			}
			else {
				vs[i].push(no);
			}
		}
	}
	for(int i=1;i<=q;i++) {
		while(!vb[i].empty()) {
			printf("%d\n", vb[i].top());
			vb[i].pop();
		}
	}
	//i--;
	while(!vs[i].empty()) {
			printf("%d\n", vs[i].top());
			vs[i].pop();
	}
	return 0;
}