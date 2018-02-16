#include <bits/stdc++.h>

using namespace std;

bool checkBoundry(int a,int b){
	if(a>=8 || a<0 || b<0 || b>=8)
		return false;
	return true;
}

void changeByQueen(vector<vector<char>>& board,pair<int,int> position, pair<int,int> king_position){
	int x=position.first;
	int y=position.second;



	int ki,kj;
	ki=king_position.first;
	kj=king_position.second;

	char king=board[ki][kj];

	for(int i=-1;i<=1;i++){
		for(int j=-1;j<=1;j++){
			if(i==0 && j==0){
				continue;
			}
			int a=x+i;
			int b=y+j;
			while(checkBoundry(a,b) && board[ki][kj]==king && (board[a][b]=='#' || board[a][b]==king)){
				if(board[a][b]==king){
					board[a][b]='Q';
				}
				a=a+i;
				b=b+j;
			}
		}
	}
}
void changeByBishop(vector<vector<char>>& board,pair<int,int> position,pair<int,int> king_position){

	int ki=king_position.first;
	int kj=king_position.second;

	char king=board[ki][kj];

	int x=position.first;
	int y=position.second;

	for(int i=-1;i<=1;i+=2){
		for(int j=-1;j<=1;j+=2){
			int a=x+i;
			int b=y+j;
			while(checkBoundry(a,b) && board[ki][kj]==king && (board[a][b]=='#' || board[a][b]==king)){
				if(board[a][b]==king){
					board[a][b]='B';
				}
				a=a+i;
				b=b+j;
			}
			
		}
	}
	
}

void changeByRook(vector<vector<char>>& board,pair<int,int> position,pair<int,int> king_position){

	int ki=king_position.first;
	int kj=king_position.second;

	char king=board[ki][kj];

	int x=position.first;
	int y=position.second;

	int i=x-1;
	int j=y;

	while(checkBoundry(i,j) && board[ki][kj]==king && (board[i][j]=='#' || board[i][j]==king)){
		if(board[i][j]==king){
				board[i][j]='R';
		}
		i--;
	}
	i=x+1;
	j=y;
	while(checkBoundry(i,j) && board[ki][kj]==king && (board[i][j]=='#' || board[i][j]==king)){
		if(board[i][j]==king){
				board[i][j]='R';
		}
		i++;
	}
	i=x;
	j=y-1;
	while(checkBoundry(i,j) && board[ki][kj]==king && (board[i][j]=='#' || board[i][j]==king)){
		if(board[i][j]==king){
				board[i][j]='R';
		}
		j--;
	}
	i=x;
	j=y+1;
	while(checkBoundry(i,j) && board[ki][kj]==king && (board[i][j]=='#' || board[i][j]==king)){
		if(board[i][j]==king){
				board[i][j]='R';
		}
		j++;
	}
}
void changeByKnight(vector<vector<char>>& board,pair<int,int> position,pair<int,int> king_position){

	int ki=king_position.first;
	int kj=king_position.second;

	int x=position.first;
	int y=position.second;
	int i,j;

	i=x+1;
	j=y-2;
	if(checkBoundry(i,j) && board[i][j]=='k'){
		board[i][j]='N';
	}

	i=x+1;
	j=y+2;
	if(checkBoundry(i,j) && board[i][j]=='k'){
		board[i][j]='N';
	}

	i=x+2;
	j=y-1;
	if(checkBoundry(i,j) && board[i][j]=='k'){
		board[i][j]='N';
	}

	i=x+2;
	j=y+1;
	if(checkBoundry(i,j) && board[i][j]=='k'){
			board[i][j]='N';
	}
}
void modify_board(vector<vector<char>>& board, map<char,pair<int,int>> mp,pair<int,int> king_position){
	int x=king_position.first;
	int y=king_position.second;
	for(auto i=mp.begin();i!=mp.end() && board[x][y]=='k';i++){
		if(i->first=='Q'){
			changeByQueen(board,i->second,king_position);
		}
		else if(i->first=='B'){
			changeByBishop(board,i->second,king_position);
		}
		else if(i->first=='R'){
			changeByRook(board,i->second,king_position);
		}
	}
}

bool validMove(vector<vector<char>>& board, map<char,pair<int,int>> mp_black,pair<int,int> king_position_w){
	int x=king_position_w.first;
	int y=king_position_w.second;
	for(auto i=mp_black.begin();i!=mp_black.end();i++){
		if(i->first=='q'){
			changeByQueen(board,i->second,king_position_w);
		}
		else if(i->first=='b'){
			changeByBishop(board,i->second,king_position_w);
		}
		else if(i->first=='r'){
			changeByRook(board,i->second,king_position_w);
		}
		if(board[x][y]!='K'){
			board[x][y]='K';
			return false;
		}
	}
	return true;
}

int waysToGiveACheck(vector<vector<char>> board,map<char,pair<int,int>> mp,pair<int,int> king_position,map<char,pair<int,int>> mp_black,pair<int,int> king_position_w) {
// Complete this function
	pair<int,int> promotion_pos;
	for(int j=0;j<8;j++){
		if(board[1][j]=='P' && board[0][j]=='#'){
			board[1][j]='#';
			if(validMove(board,mp_black,king_position_w)){
				board[0][j]='P';
				promotion_pos=make_pair(0,j);
				break;
			}
			else{
				board[1][j]='P';
			}
		}
	}
	modify_board(board,mp,king_position);
	int x=king_position.first;
	int y=king_position.second;
	if(board[x][y]!='k'){
		return 4;
	}
	else{
		changeByKnight(board,promotion_pos,king_position);
		if(board[x][y]!='k'){
			return 1;
		}
		changeByBishop(board,promotion_pos,king_position);
		if(board[x][y]!='k'){
			return 2;
		}
		changeByRook(board,promotion_pos,king_position);
		if(board[x][y]!='k'){
			return 2;
		}
	}
	return 0;
}

int main() {
	int t;
	cin >> t;
	map<char,pair<int,int>> mp;
	map<char,pair<int,int>> mp_black;

	pair<int,int> king_position;
	pair<int,int> king_position_w;
	for(int a0 = 0; a0 < t; a0++){
		vector< vector<char> > board(8,vector<char>(8));
			for(int board_i = 0;board_i < 8;board_i++){
				for(int board_j = 0;board_j < 8;board_j++){
				cin >> board[board_i][board_j];
				if(board[board_i][board_j]=='Q' || board[board_i][board_j]=='B' || board[board_i][board_j]=='R'){
					mp[board[board_i][board_j]]=make_pair(board_i,board_j);
				}
				if(board[board_i][board_j]=='q' || board[board_i][board_j]=='b' || board[board_i][board_j]=='r'){
					mp_black[board[board_i][board_j]]=make_pair(board_i,board_j);
				}
				if(board[board_i][board_j]=='k'){
					king_position=make_pair(board_i,board_j);
				}
				if(board[board_i][board_j]=='K'){
					king_position_w=make_pair(board_i,board_j);
				}
			}
		}
		int result = waysToGiveACheck(board,mp,king_position,mp_black,king_position_w);
		cout << result << endl;
	}
	return 0;
}
