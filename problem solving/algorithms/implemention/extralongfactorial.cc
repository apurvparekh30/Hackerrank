#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	list<int> l;

	l.push_front(1);
	
	int carry = 0;
	
	for(int i=2;i<=n;i++) {
		int len = l.size();
		int j=0;
		carry = 0;
		while(j<len){
			int n = l.back();
			l.pop_back();
			int temp = (n*i) + carry;
			int dig = temp % 10;
			l.push_front(dig);
			carry = temp/10;
			j++;
		}
		while(carry) {
			int dig = carry % 10;
			l.push_front(dig);
			carry = carry / 10;
		}
	}

	while(!l.empty()){
		cout<<l.front();
		l.pop_front();
	}
	return 0;
}