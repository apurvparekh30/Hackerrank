#include <bits/stdc++.h>

using namespace std;

bool updateBoard(vector<vector<char>> & board,pair<int,int> loc,char move) {
	int r,c;
	r=loc.first;
	c=loc.second;
	if(board[r][c]=='+') {
		board[r][c]='W';
		return true;
	}
	if(board[r][c]=='.') {
		board[r][c]='w';
		return true;
	}
	if(board[r][c]=='#') {
		return false;
	}
	if(board[r][c]=='b' || board[r][c]=='B') {
		if(move=='L') {
			if(board[r][c-1] == 'b' || board[r][c-1]=='#' || board[r][c-1]=='B') {
				return false;
			}
			else {
				if(board[r][c-1]=='+')
					board[r][c-1]='B';
				else
					board[r][c-1]='b';
				if(board[r][c]=='b')
					board[r][c]='w';
				else
					board[r][c]='W';
				return true;	
			}
		}
		else if(move=='R'){
			if(board[r][c+1] == 'b' || board[r][c+1]=='#' || board[r][c+1]=='B') {
				return false;
			}
			else {
				if(board[r][c+1]=='+')
					board[r][c+1]='B';
				else
					board[r][c+1]='b';

				if(board[r][c]=='b')
					board[r][c]='w';
				else
					board[r][c]='W';

				return true;	
			}

		}
		else if(move=='U') {
			if(board[r-1][c] == 'b' || board[r-1][c]=='#' || board[r-1][c]=='B') {
				return false;
			}
			else {
				if(board[r-1][c]=='+')
					board[r-1][c]='B';
				else
					board[r-1][c]='b';

				if(board[r][c]=='b')
					board[r][c]='w';
				else
					board[r][c]='W';

				return true;	
			}

		}
		else if(move=='D'){
			if(board[r+1][c] == 'b' || board[r+1][c]=='#' || board[r+1][c]=='B') {
				return false;
			}
			else {
				if(board[r+1][c]=='+')
					board[r+1][c]='B';
				else
					board[r+1][c]='b';

				if(board[r][c]=='b')
					board[r][c]='w';
				else
					board[r][c]='W';

				return true;	
			}

		}
	}

}


int main() {
	int count=1;
	while(1) {
		int r,c;
		cin>>r>>c;
		if(r==0 && c==0) {
			break;
		}
		vector<vector<char>> board(r,vector<char>(c));
		vector<pair<int,int>> target;
		//map<pair<int,int>,bool> mp;
		pair<int,int> wloc;
		for(int i=0;i<r;i++) {
			for(int j=0;j<c;j++) {
				cin>>board[i][j];
				if(board[i][j]=='+' || board[i][j]=='W' || board[i][j]=='B') {
					target.push_back(make_pair(i,j));
					//mp[make_pair(i,j)]=true;
				}
				if(board[i][j]=='w' || board[i][j]=='W') {
					wloc=make_pair(i,j);
				}
			}
		}
		string moves;
		cin>>moves;
		pair<int,int> newloc;
		bool flag=true;
	//	bool myflag=true;
		for(auto i:moves) {
			if(i=='U') {
				newloc=make_pair(wloc.first-1,wloc.second);
				if(flag) {
				if(updateBoard(board,newloc,'U')) {
					if(board[wloc.first][wloc.second]=='W')
						board[wloc.first][wloc.second]='+';
					else 
						board[wloc.first][wloc.second]='.';
					wloc=newloc;

				}
				}
			}
			else if(i=='D') {
				newloc=make_pair(wloc.first+1,wloc.second);
				if(flag) {
				if(updateBoard(board,newloc,'D')) {
					if(board[wloc.first][wloc.second]=='W')
						board[wloc.first][wloc.second]='+';
					else 
						board[wloc.first][wloc.second]='.';

					wloc=newloc;

				}
				}

			}
			else if(i=='L') {
				newloc=make_pair(wloc.first,wloc.second-1);
				if(flag){
				if(updateBoard(board,newloc,'L')) {
					if(board[wloc.first][wloc.second]=='W')
						board[wloc.first][wloc.second]='+';
					else 
						board[wloc.first][wloc.second]='.';

					wloc=newloc;

				}
				}
			}
			else if(i=='R'){
				newloc=make_pair(wloc.first,wloc.second+1);
				if(flag){
				if(updateBoard(board,newloc,'R')) {
					if(board[wloc.first][wloc.second]=='W')
						board[wloc.first][wloc.second]='+';
					else 
						board[wloc.first][wloc.second]='.';

					wloc=newloc;
				}
				}
			}
			if(flag){
			bool myflag=true;
			for(auto j:target) {
				int r=j.first;
				int c=j.second;
			
				if(board[r][c]!='B'){
					myflag=false;
					break;
				}
			}	
				if(myflag) {
					flag=false;
				}
			}
			/*cout<<i<<endl;
			for(int i=0;i<r;i++) {
				for(int j=0;j<c;j++) {
					cout<<board[i][j];
				}		
				cout<<'\n';
			}
			cout<< endl;*/

		}
			
		/*cout<<"\n\nfinal";*/
		if(!flag) {
			cout<<"Game "<<count<<": complete"<<'\n';
		}
		else {
			cout<<"Game "<<count<<": incomplete"<<'\n';
		}
		for(int i=0;i<r;i++) {
			for(int j=0;j<c;j++) {
				cout<<board[i][j];
			}		
			cout<<'\n';
		}
		count++;
	}
}
