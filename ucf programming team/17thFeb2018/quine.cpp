#include <bits/stdc++.h>
using namespace std;

bool onlyalpha(string token1){
	for(char c:token1){
		if(!isalpha(c)){
			if(c!=' ')
				return false;
		}
	}
	return true;
}
int main(){
	string s;
	while(1){
		getline(cin,s);
		if(s=="END")
			break;
		else {
			if(s[0]!='\"'){
				cout<<"not a quine"<<endl;	
			}
			else{
				string delimiter="\" ";
				s.erase(0,1);
				if(s[0]=='\"'){
					cout<<"not a quine"<<endl;
				}
				else{
					size_t pos=s.find(delimiter);
					if(pos>=s.length()){
						cout<<"not a quine"<<endl;
					}
					else{
						string token1=s.substr(0,pos);
						s.erase(0,pos+delimiter.length());
						string token2=s;
						if(!onlyalpha(token1)){
							cout<<"not a quine"<<endl;
						}
						else{
							if(token1==token2){
								cout<<"Quine("<<token2<<")"<<endl;
							}
							else{
								cout<<"not a quine"<<endl;
							}
						}
					}
				}
			}
		}
	}
	return 0;
}