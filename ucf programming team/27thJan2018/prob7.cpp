#include <bits/stdc++.h>
using namespace std;

int getCost(list<int> lt[], vector<int> costAt,int core){
	if(lt[core].empty()){
		return costAt[core];
	}
	int costFrom=0;
	for(list<int>::iterator i=lt[core].begin();i!=lt[core].end();i++){
		costFrom+=getCost(lt,costAt,*i);
	}
	return min(costAt[core],costFrom);
}

int main(){
	int n;
	cin>>n;
	while(n--){
		int t;
		cin>>t;
		list<int> lt[t+1];
		vector<int> costAt(t+1);
		costAt[0]=4001;
		for(int i=1;i<=t;i++){
			int index;
			int p;
			cin>>index;
			cin>>costAt[index];
			cin>>p;
			lt[p].push_back(index);
		}
		cout<<getCost(lt,costAt,0)<<endl;
	}
	return 0;
}