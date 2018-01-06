#include <bits/stdc++.h>
using namespace std;
int main() {

    ifstream inFile;
    inFile.open("input.txt");
	stack<char> st;
	stack<char> t;
	stack<stack<char>> stbk;
	long q;
	long l;
	inFile>>q;
	//cin >> q;
	while(q--) {
		string w;
		long k;
		int choice;
		long temp;
		inFile>>choice;
		//cin>>choice;

		switch(choice) {
			case 1:
				inFile>>w;
				//cin>>w;
				l = w.length();
				for(long i=0;i<l;i++){
					st.push(w[i]);
				}
				stbk.push(st);
				break;
			case 2:
				inFile>>k;
				//cin>>k;
				while(k--) {
					st.pop();
				}
				stbk.push(st);
				break;
			case 3:
				inFile>>k;
				//cin>>k;
				temp = st.size() - k;
				while(temp--) {
					char ch = st.top();
					st.pop();
					t.push(ch);
				}
				printf("%c\n",st.top());
				while(!t.empty()) {
					st.push(t.top());
					t.pop();
				}
				break;
			case 4:
					stbk.pop();
					if(!stbk.empty())
						st = stbk.top();
					
		}
	}
	return 0;
}