#include <bits/stdc++.h>
using namespace std;
int main(){
	vector<int> v;
	map<char,int> mp;
	while(1){
		int score;
		cin>>score;
		if(score<0){
			break;
		}
		if(score>=90){
			mp['A']++;
		}
		else if(score>=80){
			mp['B']++;
		}
		else if(score>=70){
			mp['C']++;
		}
		else if(score>=60) {
			mp['D']++;
		}
		else{
			mp['F']++;
		}
		v.push_back(score);
	}
	sort(v.begin(),v.end(),[](int a,int b){return a<b;});
	double median;
	if(v.size()%2==0){
		int i1=v.size()/2;
		median=(double)(v[i1]+v[i1-1])/2;
	}
	else{
		median=(double)v[v.size()/2];
	}
	printf("Median = %2.1lf%%\n",median);
	cout<<"High Score = "<<v[v.size()-1]<<endl;
	for(char i='A';i<='F';i++){
		if(i=='E')
			continue;
		cout<<i<<"s = "<<mp[i]<<endl;
	}
	return 0;
}