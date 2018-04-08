#include <bits/stdc++.h>
#define boost ios::sync_with_stdio(false);cin.tie(NULL);

using namespace std;

pair<int,int> get_min_x(int l,int m,vector<pair<int,int>> houses,pair<int,int> ignore){
	int min=INT_MAX;
	pair<int,int> p;
	for(int i=l;i<=m;i++) {
		if(houses[i]!=ignore) {
			if(min>houses[i].first) {
				min=houses[i].first;
				p=houses[i];
			}
		}
	}
	return p;
}

pair<int,int> get_min_y(int l,int m,vector<pair<int,int>> houses,pair<int,int> ignore){
	int min=INT_MAX;
	pair<int,int> p;
	for(int i=l;i<=m;i++) {
		if(houses[i]!=ignore) {
			if(min>houses[i].second) {
				min=houses[i].second;
				p=houses[i];
			}
		}
	}
	return p;
}
pair<int,int> get_max_x(int l,int m,vector<pair<int,int>> houses,pair<int,int> ignore){
	int max=INT_MIN;
	pair<int,int> p;
	for(int i=l;i<=m;i++) {
		if(houses[i]!=ignore) {
			if(max<houses[i].first) {
				max=houses[i].first;
				p=houses[i];
			}
		}
	}
	return p;
}
pair<int,int> get_max_y(int l,int m,vector<pair<int,int>> houses,pair<int,int> ignore){
	int max=INT_MIN;
	pair<int,int> p;
	for(int i=l;i<=m;i++) {
		if(houses[i]!=ignore){//if(houses[i].first!=ignore.first && houses[i].second!=ignore.second) {
			if(max<houses[i].second) {
				max=houses[i].second;
				p=houses[i];
			}
		}
	}
	return p;
}
bool min_x(pair<int,int> a,pair<int,int> b) {
	return a.first<b.first;
}
bool min_y(pair<int,int> a,pair<int,int> b) {
	return a.second<b.second;
}
bool max_x(pair<int,int> a,pair<int,int> b) {
	return a.first<b.first;
}
bool max_y(pair<int,int> a,pair<int,int> b) {
	return a.second<b.second;
}

int main() {
	boost;
	int n,q;
	cin>>n>>q;
	vector<pair<int,int>> houses(n+1);
	for(int i=1;i<=n;i++) {
		int x,y;
		cin>>x>>y;
		houses[i]=make_pair(x,y);
	}
	for(int i=0;i<q;i++) {
		int l,m,result;
		cin>>l>>m;
		vector<pair<int,int>> temp(4);
		temp[0]=*min_element(houses.begin()+l,houses.begin()+m+1,min_x);
		temp[1]=*min_element(houses.begin()+l,houses.begin()+m+1,min_y);
		temp[2]=*max_element(houses.begin()+l,houses.begin()+m+1,max_x);
		temp[3]=*max_element(houses.begin()+l,houses.begin()+m+1,max_y);
		pair<int,int> one=make_pair(temp[0].first,temp[1].second);
		pair<int,int> two=make_pair(temp[2].first,temp[3].second);
		result=max(abs(one.first-two.first),abs(one.second-two.second));
	result=min(result,min(max(abs(temp[0].first-two.first),abs(temp[0].second-two.second)),max(abs(temp[1].first-two.first),abs(temp[1].second-two.second))));
	result=min(result,min(max(abs(temp[2].first-one.first),abs(temp[2].second-one.second)),max(abs(temp[3].first-one.first),abs(temp[3].second-one.second))));
		/*int count=0;
		pair<int,int> minx,miny,maxx,maxy;
		for(auto i:temp) {
			minx=temp[0];
			miny=temp[1];
			maxx=temp[2];
			maxy=temp[3];
	
			switch (count){
				case 0:minx=get_min_x(l,m,houses,i);break;
				case 1:miny=get_min_y(l,m,houses,i);break;
				case 2:maxx=get_max_x(l,m,houses,i);break;
				case 3:maxy=get_max_y(l,m,houses,i);break;
			}
			pair<int,int> one=make_pair(minx.first,miny.second);
			pair<int,int> two=make_pair(maxx.first,maxy.second);
			result=min(result,max(abs(one.first-two.first),abs(one.second-two.second)));
			count++;
		}*/
		cout<<result<<'\n';
	}
	
	return 0;
}
