
#include <bits/stdc++.h>
#define pp pair<pair<int,int>,int>
using namespace std;

/*
 * Complete the dynamicLineIntersection function below.
 */

/*struct point{
	float x,y;
};

struct line {
	int a,b,c;
	bool operator<(const line &l) const{
		return (a<l.a && b<l.b && c<l.c);
	}
};*/

map<pp,int> mp;

pp setLine(int k,int b) {
	pp l;
	l.first.first=-k;
	l.first.second=1;
	l.second=-b;
	return l;
}

pp setLine(int q) {
	pp l;
	l.first.first=0;
	l.first.second=1;
	l.second=-q;
	return l;
}
void addLine(pp l) {
	mp[l]++;
}
void removeLine(pp l) {
	mp[l]--;
}
bool areParallel(pp l1,pp l2) {
	return ((l1.first.first==l2.first.first) && (l1.first.second==l2.first.second)); 
}
bool areIntersect(pp l1,pp l2) {
	float x;
	if(areParallel(l1,l2)) {
		return false;
	}
	x=((float)(l2.first.second*l1.second - l1.first.second*l2.second)/(float)(l2.first.first*l1.first.second - l1.first.first*l2.first.second));
	return ceil(x ) == x;
}
void dynamicLineIntersection(int n) {
    /*
     * Write your code here.
     */
	while(n--) {
		char ch;	
		cin>>ch;
		if(ch=='+' || ch=='-') {
			int k,b;
			cin>>k>>b;
			pp l = setLine(k,b);
			if(ch == '+') 
				addLine(l);
			else 
				removeLine(l);
		}
		else {
			int q;
			cin>>q;
			int count=0;
			pp l=setLine(q);
			for(auto li:mp){
				if(li.second>0) {
					if(areIntersect(l,li.first)){
						count++;
					}
				}
			}			
			cout<<count<<'\n';
		}
	}
}

int main()
{
	int n;
    	cin >> n;
    	cin.ignore(numeric_limits<streamsize>::max(), '\n');
    	dynamicLineIntersection(n);

    return 0;
}
