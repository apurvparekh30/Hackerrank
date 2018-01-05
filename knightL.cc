#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin>>n;
	int c[n][n];
	

	for(int i=1;i<n;i++) {
		for(int j=1;j<n;j++) {
			memset(c,0,sizeof(c[0][0])*n*n);
			queue <pair<int,int>> q;
			pair<int,int> p = make_pair(0,0);
			q.push(p);
			while(!q.empty()) {
				pair<int,int> p = q.front();
				q.pop();
				if(p.first+i < n && p.second+j < n){
					int row = p.first + i;
					int col = p.second + j;
					int steps = c[p.first][p.second];
					if(c[row][col] > steps + 1 || c[row][col] == 0){
						c[row][col] = steps + 1;
						q.push(make_pair(row,col));
					}
					
				}
				if(p.first+j < n && p.second+i < n){
					int row = p.first + j;
					int col = p.second + i;
					int steps = c[p.first][p.second];
					if(c[row][col] > steps + 1 || c[row][col] == 0){
						c[row][col] = steps + 1;
						q.push(make_pair(row,col));
					}
					
				}
				if(p.first-i >= 0 && p.second+j < n){
					int row = p.first - i;
					int col = p.second + j;
					int steps = c[p.first][p.second];
					if(c[row][col] > steps + 1 || c[row][col] == 0){
						c[row][col] = steps + 1;
						q.push(make_pair(row,col));
					}
					
				}
				if(p.first-j >= 0 && p.second+i < n){
					int row = p.first - j;
					int col = p.second + i;
					int steps = c[p.first][p.second];
					if(c[row][col] > steps + 1 || c[row][col] == 0){
						c[row][col] = steps + 1;
						q.push(make_pair(row,col));
					}
					
				}
				if(p.first-j >= 0 && p.second-i >= 0){
					int row = p.first - j;
					int col = p.second - i;
					int steps = c[p.first][p.second];
					if(c[row][col] > steps + 1 || c[row][col] == 0){
						c[row][col] = steps + 1;
						q.push(make_pair(row,col));
					}
					
				}
				if(p.first-i >= 0 && p.second-j >= 0){
					int row = p.first - i;
					int col = p.second - j;
					int steps = c[p.first][p.second];
					if(c[row][col] > steps + 1 || c[row][col] == 0){
						c[row][col] = steps + 1;
						q.push(make_pair(row,col));
					}
					
				}
				if(p.first+i < n && p.second-j >= 0){
					int row = p.first + i;
					int col = p.second - j;
					int steps = c[p.first][p.second];
					if(c[row][col] > steps + 1 || c[row][col] == 0){
						c[row][col] = steps + 1;
						q.push(make_pair(row,col));
					}
					
				}
				if(p.first+j < n && p.second-i >= 0){
					int row = p.first + j;
					int col = p.second - i;
					int steps = c[p.first][p.second];
					if(c[row][col] > steps + 1 || c[row][col] == 0){
						c[row][col] = steps + 1;
						q.push(make_pair(row,col));
					}
					
				}
			}
			if(c[n-1][n-1] == 0){
				cout<<"-1"<<" ";
			}
			else {
				cout<<c[n-1][n-1]<<" ";
			}
			
		}
		cout<<endl;
	}
	
	return 0;
}