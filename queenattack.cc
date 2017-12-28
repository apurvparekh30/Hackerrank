#include <bits/stdc++.h>

using namespace std;

int main() {
	int n,k;
	cin>>n>>k;

	pair <int,int> qloc;
	int qx,qy;
	cin>>qx>>qy;

	pair <int,int> diag1,diag2,diag3,diag4,up,down,left,right;

	int m;

	m = min((n+1)-qx,qy-0);
	diag1 = make_pair(qx+m,qy-m);

	m = min((n+1)-qx,(n+1)-qy);
	diag2 = make_pair(qx+m,qy+m);

	m = min(qx-0,qy-0);
	diag3 = make_pair(qx - m,qy-m);

	m = min(qx-0,(n+1)-qy);
	diag4 = make_pair(qx-m,qy+m);

	up = make_pair(n+1,qy);
	down = make_pair(0,qy);
	left = make_pair(qx,0);
	right = make_pair(qx,n+1);

	for(int i=0;i<k;i++){
		int x,y;
		cin>>x>>y;
		if(x > qx && y < qy) {
			if((x - qx) == (qy - y)){
				if(x < diag1.first && y>diag1.second){
					diag1 = make_pair(x,y);
				}
			}
			continue;
		}
		if(x > qx && y > qy) {
			if((x - qx) == (y - qy)){
				if(x < diag2.first && y<diag2.second){
					diag2 = make_pair(x,y);
				}
			}
			continue;
		}
		if(x < qx && y < qy) {
			if((qx - x) == (qy - y)){
				if(x>diag3.first && y>diag3.second){
					diag3 = make_pair(x,y);
				}
			}
			continue;
		}
		if(x<qx && y>qy) {
			if((qx - x) == (y - qy)){
				if(x > diag4.first && y<diag4.second){
					diag4 = make_pair(x,y);
				}
			}
			continue;
		}

		if(y == qy && x > qx){
			if(up.first - qx > x - qx){
				up = make_pair(x,y);
			}
			continue;
		}
		if(y == qy && x < qx){
			if(qx - down.first > qx - x){
				down = make_pair(x,y);
			}
			continue;
		}
		if(x == qx && y < qy){
			if(qy - left.second > qy - y){
				left = make_pair(x,y);
			}
			continue;
		}
		if(x == qx && y > qy){
			if(right.second - qy > y - qy){
				right = make_pair(x,y);
			}
			continue;
		}
	}

	int count = 0;

	count = count + (diag1.first - qx);
	count = count + (diag2.first - qx);
	count = count + (qx - diag3.first);
	count = count + (qx - diag4.first);

	count = count + (up.first - qx);
	count = count + (qx - down.first);
	count = count + (qy - left.second);
	count = count + (right.second - qy);

	cout <<count-8;

	return 0;
}