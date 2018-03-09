#include <bits/stdc++.h>
using namespace std;

double inline degree2radian(int a) { 
	return (a * 0.017453292519); 
}

void getendpoints(double angle,int length,double x,double y,double *endx,double *endy){
	*endx=x+length*cos(angle);
	*endy=y+length*sin(angle);
}

bool markplane(vector<vector<int>>& v, int x,int y, int newx,int newy){
	int i,j,maxi,maxj;
	if(x==newx){
		i=x;
		j=min(y,newy);
		maxj=max(y,newy);
		for(;j<=maxj;j++){
			v[j][i]=1;
		}
		return true;
	}
	if(y==newy){
		j=y;
		i=min(x,newx);
		maxi=max(x,newx);
		for(;i<=maxi;i++){
			v[j][i]=1;
		}
		return true;
	}
	i=min(x,newx);
	j=min(y,newy);

	maxi=max(x,newx);
	maxj=max(y,newy);


	int limit=min(abs(maxi-i),abs(maxj-j));
	for(int k=0;k<=limit;k++){
		v[j++][i++]=1;
	}

	return true;
}
int main() {
	int n;
	while(1){
		double x=0,y=0;
		double newx,newy;
		cin>>n;
		if(n==0)
			break;
		vector<vector<int>> v(20,vector<int>(20));
		for(int i=0;i<n;i++){
			int angle,length;
			cin>>angle>>length;
			if(i==0)
				angle=angle+90;
			getendpoints(degree2radian(angle),length,x,y,&newx,&newy);
			bool result=markplane(v,x,y,newx,newy);
			x=newx;
			y=newy;
		}
		
	}
	return 0;
}