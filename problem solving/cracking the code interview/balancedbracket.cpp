#include <bits/stdc++.h>
using namespace std;

bool is_balanced(string expression) {
   stack<char> st;
   for(char c:expression){
   		if(c=='{'|| c=='['||c=='('){
   			st.push(c);
   			continue;
   		}	   
   		else{
   			if(st.empty()){
   				return false;
   			}
   			if(st.top()==c-1||st.top()==c-2){
   				st.pop();
   			}
   		}
   } 
   if(st.empty()){
   		return true;
   }
   else{
   		return false;
   }
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        string expression;
        cin >> expression;
        bool answer = is_balanced(expression);
        if(answer)
            cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
