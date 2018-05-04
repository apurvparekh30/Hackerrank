#include <bits/stdc++.h>
using namespace std;

bool checkBoundry(int a,int b){
        if(a<0 || a>=5 || b<0 || b>=5)
                return false;
        return true;
}

string getResult(queue<pair<int,int>> q,vector<string> v){
	while(!q.empty()){
		int r=q.front().first;
		int c=q.front().second;
		q.pop();
		if(checkBoundry(r+1,c-2)){
			if(v[r+1][c-2]=='k'){
				return "invalid";
			}
		}
		if(checkBoundry(r+1,c+2)){
			if(v[r+1][c+2]=='k'){
				return "invalid";
			}
		}
		if(checkBoundry(r-1,c-2)){
			if(v[r-1][c-2]=='k'){
				return "invalid";
			}
		}
		if(checkBoundry(r-1,c+2)){
			if(v[r-1][c+2]=='k'){
				return "invalid";
			}
		}
		if(checkBoundry(r+2,c-1)){
			if(v[r+2][c-1]=='k'){
				return "invalid";
			}
		}
		if(checkBoundry(r+2,c+1)){
			if(v[r+2][c+1]=='k'){
				return "invalid";
			}
		}
		if(checkBoundry(r-2,c-1)){
			if(v[r-2][c-1]=='k'){
				return "invalid";
			}
		}
		if(checkBoundry(r-2,c+1)){
			if(v[r-2][c+1]=='k'){
				return "invalid";
			}
		}
	}
	return "valid";
}
int main(){
	vector<string> v(5);
	int count=0;
	queue<pair<int,int>> q;
	for(int i=0;i<5;i++){
		cin>>v[i];
		for(int j=0;j<5;j++){
			if(v[i][j]=='k'){
				count++;
				q.push(make_pair(i,j));
			}
		}
	}
	if(count==9){
		cout<<getResult(q,v)<<endl;
	}
	else{
		cout<<"invalid"<<endl;
	}
	return 0;
}