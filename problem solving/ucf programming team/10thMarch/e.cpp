#include <bits/stdc++.h>
using namespace std;

bool checkboundry(int a,int b,int n,int m) {
	if(a<0 || a>=n || b<0 || b>=m) 
		return false;
	return true;
}

int main() {
	while(1) {
		int n,m,k;
		cin>>n>>m>>k;
		if(!n && !m && !k){
			break;
		}
		vector<vector<char>> v(n,vector<char>(m));
		vector<vector<int>> d(n,vector<int>(m,INT_MAX));
		vector<pair<int,int>> fire;
		pair<int,int> start;
		pair<int,int> end;
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) { 
				cin>>v[i][j];
				if(v[i][j]=='f') {
					fire.push_back(make_pair(i,j));
				}
				else if(v[i][j]=='s') {
					start.first=i;
					start.second=j;
				}
				else if(v[i][j]=='t') {
					end.first=i;
					end.second=j;
				}
			}
		}
		queue<pair<int,int>> q;
		q.push(start);
		d[start.first][start.second]=0;
		int currstep=0;
		bool flag=true;
		while(!q.empty()) {
			pair<int,int> currnode=q.front();
			q.pop();
			if(currstep != d[currnode.first][currnode.second]){
				currstep=d[currnode.first][currnode.second];
				flag=true;
			}
			if((currstep+1) % k == 0 && flag){
				vector<pair<int,int>> temp;	
				for(auto i:fire) {
					int a,b;
					a=i.first;
					b=i.second;	
					for(int j=-1;j<=1;j++) {
						for(int k=-1;k<=1;k++) {
							if(j!=0 || k!=0) {
								if(checkboundry(a+j,b+k,n,m)) {
									if(v[a+j][b+k]!='f'){
										v[a+j][b+k]='f';
										temp.push_back(make_pair(a+j,b+k));
									}
								}	
							}	
						}
					}
				}
				fire.insert(fire.end(),temp.begin(),temp.end());
				flag=false;
			}
			int a,b;
			a=currnode.first;
			b=currnode.second;
			if(checkboundry(a-1,b,n,m)){
				if(v[a-1][b]!='f') {
					if(d[a-1][b]>d[a][b]+1) {
						d[a-1][b]=d[a][b]+1;
						q.push(make_pair(a-1,b));
					}
				}	
			}	
			if(checkboundry(a,b-1,n,m)){
				if(v[a][b-1]!='f') {
					if(d[a][b-1]>d[a][b]+1) {
						d[a][b-1]=d[a][b]+1;
						q.push(make_pair(a,b-1));
					}
				}	
			}
			if(checkboundry(a,b+1,n,m)) {
				if(v[a][b+1]!='f') {
					if(d[a][b+1]>d[a][b]+1) {
						d[a][b+1]=d[a][b]+1;
						q.push(make_pair(a,b+1));
					}
				}	
			}
			if(checkboundry(a+1,b,n,m)) {
				if(v[a+1][b]!='f') {
					if(d[a+1][b]>d[a][b]+1) {
						d[a+1][b]=d[a][b]+1;
						q.push(make_pair(a+1,b));
					}
				}	
			}
		}
		int a,b;
		a=end.first;
		b=end.second;
		if(d[a][b]==INT_MAX) {
			cout<<"Impossible"<<endl;
		}
		else {
			cout<<d[a][b]<<endl;
		}
	}
	return 0;
}
