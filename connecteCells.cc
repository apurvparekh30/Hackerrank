#include <bits/stdc++.h>

using namespace std;

bool checkB(int a,int b,int n,int m)
{
	if(a>=n || a<0 || b>=m || b<0)
		return false;
	return true;
}

int main() {
	int m,n;

	cin>>n>>m;
	vector<vector<int>> a(n,vector<int>(m));
	vector<vector<int>> v(n,vector<int>(m));

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a[i][j];
		}
	}
	int max = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(!v[i][j] && a[i][j] == 1) {
				int count=0;
				queue<pair<int,int>> q;
				q.push(make_pair(i,j));
                v[i][j]=1;
				while(!q.empty()){
					bool check;
					pair<int,int> front = q.front();
					q.pop();
					count++;
					int row=front.first;
					int col=front.second;
					for(int x=-1;x<=1;x++){
						for(int y=-1;y<=1;y++){
                            if(x==0 && y==0){
                                continue;
                            }
							check = checkB(row+x,col+y,n,m);
							if(check && !v[row+x][col+y] && a[row+x][col+y]==1){
								q.push(make_pair(row+x,col+y));
								v[row+x][col+y]=1;
							}
						}
					}
				}
				if(max < count){
					max=count;
				}
			}
		}
	}

	cout<<max;

	return 0;
}