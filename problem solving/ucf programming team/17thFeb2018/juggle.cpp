#include <bits/stdc++.h>
using namespace std;

int main() {
	int p;
	cin>>p;
	while(p!=0){
		vector<char> v(20);
		deque <int> dq;
		char ch='A';
		bool crash=false;
		for(int i=0;i<p;i++){
			int h;
			cin>>h;
			dq.push_back(h);
		}
		for(int i=0;i<20;i++){
			if(!isalpha(v[i])){
				v[i]=ch;
				ch++;
			}
			int h=dq.front();
			dq.pop_front();
			dq.push_back(h);
			if(i+h<20){
				if(isalpha(v[i+h])){
					crash=true;
					break;
				}
				else{
					v[i+h]=v[i];
				}
			}
		}
		if(crash){
			cout<<"CRASH"<<endl;
		}
		else{
			for(char i:v){
				cout<<i;
			}
			cout<<endl;
		}
		cin>>p;
	}
	return 0;
}