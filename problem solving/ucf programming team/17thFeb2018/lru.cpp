#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int count=1;
	while(n!=0){
		cout<< "Simulation "<<count<<endl;
		string s;
		cin>>s;
		deque<char> dq;
		stack<char> st;
		map<char,bool> mp;
		for(char c:s){	
			if(c=='!'){
				for(char ch:dq){
					cout<<ch;
				}
				cout<<endl;
			}
			else {
				if(mp[c]){
					while(dq.front()!=c){
						st.push(dq.front());
						dq.pop_front();
					}
					dq.push_back(dq.front());
					dq.pop_front();
					while(!st.empty()){
						dq.push_front(st.top());
						st.pop();
					}
				}
				else {
					if(dq.size()>=n){
						mp[dq.front()]=false;
						dq.pop_front();	
					}
					dq.push_back(c);
					mp[c]=true;	
				}
			}
		}
		count++;
		cin>>n;
	}
	return 0;
}