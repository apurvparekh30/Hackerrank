#include <bits/stdc++.h>
//#define boost ios::sync_with_stdio(false);cin.tie(NULL);

using namespace std;

int main() {
	//boost;
	int count=1;
	while(1) {
		int n;
		cin>>n;
		if(n==0) {
			break;
		}
		vector<double> size(n),cost(n);
		for(int i=0;i<n;i++) {
			cin>>size[i];
			size[i]=size[i];
			cin>>cost[i];
			cost[i]=cost[i]*100;
		}
		double area;
		double mincost=DBL_MAX;
		int bestvalue;
		for(int i=0;i<n;i++) {
			double radius=size[i]/2;
			area=3.14 * radius * radius;
			double newcost=cost[i]/area;
			if(mincost > newcost) {
				mincost=newcost;
				bestvalue=size[i];
			}
		}
		cout<< "Menu "<<count<<": "<<bestvalue<<'\n';
		count++;
	}
	return 0;
}
