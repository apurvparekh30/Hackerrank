#include <bits/stdc++.h>

using namespace std;

struct submission {
	string prob;
	string result;
	int minute;
};


int main(){
	vector<submission> v;
	string s;
	while(1){
		submission temp;
		cin>>s;
		if(s=="-1"){
			break;
		}
		temp.minute = stoi(s);
		cin>>s;
		temp.prob = s;
		cin>>s;
		temp.result= s;

		v.push_back(temp);
	}		
	map<string,int> penalty;
	map<string,int> probsolved;
	int total=0;
	int solved = 0;
	for(int i=0;i<v.size();i++) {
		if(v[i].result == "right" && !probsolved[v[i].prob]) {
			total = total+v[i].minute+penalty[v[i].prob];
			solved++;
		}
		else {
			penalty[v[i].prob]+=20;
		}
	}

	cout <<solved<<" "<<total;
	return 0;
}