#include <bits/stdc++.h>

using namespace std;

int main() {
	stack <long> st1;
	stack <long> st2;

	long q;
	cin>>q;
	long x;
	while(q--) {
		int type;
		cin>>type;

		switch(type){
			case 1:
				cin>>x;
				st1.push(x);
				break;
			case 2:
				if(st2.empty()){
					while(!st1.empty()){
						st2.push(st1.top());
						st1.pop();
					}
				}
				st2.pop();
				break;
			case 3:
				if(st2.empty()){
					while(!st1.empty()){
						st2.push(st1.top());
						st1.pop();
					}
				}
				cout << st2.top()<<endl;
				break;
		}
	}
	return 0;
}