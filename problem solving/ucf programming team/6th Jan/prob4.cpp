#include <bits/stdc++.h>

using namespace std;

struct address{
	string exit;
	int dist;   //exit dis from city
	float edist;  // starbucks distance from exit
};

bool compareDist(address a, address b){
	return (a.dist<b.dist);
}

bool compareExitDist(address a, address b){
	if(a.dist == b.dist)
		return (a.edist<b.edist);
	return a.dist<b.dist;
}

int main(){

	std::vector<address> v;
	string s;
	while(1) {
		getline(cin,s);
		if(s=="END")
			break;
		int cpos=s.find(",");
		string ename = s.substr(0,cpos);
		s = s.substr(cpos+1);
		cpos=s.find(",");
		string dist=s.substr(0,cpos);
		int d = stoi(dist);
		s = s.substr(cpos+1);
		cpos=s.find(",");
		string sdist=s.substr(0,cpos);
		float sd = stof(sdist);

		if(sd<=(float)2.0){
			address a;
			a.exit = ename;
			a.dist=d;
			a.edist=sd;
			v.push_back(a);
		}
	}
	sort(v.begin(),v.end(),compareDist);
	sort(v.begin(),v.end(),compareExitDist);

	for(int i=0;i<v.size();i++){
		cout<<v[i].exit<<", Exit "<<v[i].dist<<endl;
	}
	return 0;
}