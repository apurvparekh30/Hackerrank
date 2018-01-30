#include <bits/stdc++.h>
using namespace std;

string getAnswer(vector<int> v,int curr,int index){
	if(curr%101==0){
		string res="";
		for(int i=index;i<v.size();i++){
			res+="*"+to_string(v[i]);
		}
		return res+" ";
	}
	if(index>=v.size()){
		return "";
	}
	string res=getAnswer(v,curr+v[index],index+1);
	if(res!=""){
		return "+"+to_string(v[index])+res;
	}
	res=getAnswer(v,curr-v[index],index+1);
	if(res!=""){
		return "-"+to_string(v[index])+res;
	}
	res=getAnswer(v,curr*v[index],index+1);
	if(res!=""){
		return "*"+to_string(v[index])+res;
	}
	return "";
}

int main(){
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	string result=to_string(v[0]);
	result=result+getAnswer(v,v[0],1);
	cout<<result;
}