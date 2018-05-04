#include <bits/stdc++.h>
using namespace std;

int main() {
	int p;
	cin>>p;
	while(p--) {
		int tno;
		cin>>tno;
		int r,c;
		cin>>r>>c;
		vector<vector<int>> grid(r,vector<int>(c));
		for(int i=0;i<r;i++) {
			for(int j=0;j<c;j++) {
				char ch;
				cin>>ch;
				if(ch != '-') {
					grid[i][j]=ch-'0';	
				}
			}
		}
		int reg;
		cin>>reg;
		vector<vector<string>> v(reg);
		for(int i=0;i<reg;i++) {
			int n;
			cin>>n;
			for(int j=0;j<n;j++) {
				string s;
				cin>>s;
				v[i].push_back(s);
			}
		}
		
	}
}
