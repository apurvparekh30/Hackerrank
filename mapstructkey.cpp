#include <bits/stdc++.h>
using namespace std;

struct line {
	int a,b,c;
	bool operator<(const line &l) const{
		return (a<l.a && b<l.b && c<l.c);
	}
};

struct line1{
	int a,b,c;
};


struct comp {
	bool operator() (line1 l1,line1 l2) {
		//return (l1.a<l2.a && l1.b<l2.b && l1.c<l2.c);
		return make_pair(make_pair(l1.a,l1.b),l1.c) <= make_pair(make_pair(l2.a,l2.b),l2.c);
	}
};

map <line,int> mp;
map <line1,int,comp> mp1;
int main() {
	line l1;
	l1.a=0;l1.b=1;l1.c=0;
	line l2;
	l2.a=-2;l2.b=1;l2.c=0;
	mp[l1]++;
	mp[l2]++;

	line1 l3;
	l3.a=0;l3.b=1;l3.c=0;
	line1 l4;
	l4.a=-2;l4.b=1;l4.c=0;
	mp1[l3]++;
	mp1[l4]++;

	
	cout<<"hello";
	return 0;
}	
