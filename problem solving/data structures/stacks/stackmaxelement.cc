#include <bits/stdc++.h>

using namespace std;


int main(){
    long n;
    long x;
    long t;
    scanf("%ld",&n);
    stack <long> st;
    stack <long> maxst;
    long temp;
    maxst.push(0);

    while(n--) {
        scanf("%ld",&t); 
        switch (t) {
            case 1:
                scanf("%ld",&x);
                if(maxst.top() <= x){
                    maxst.push(x);
                }
                st.push(x);
                break;
            case 2:
                if(maxst.top() == st.top()){
                    maxst.pop();
                }
                st.pop();
                break;
            case 3:
                printf("%ld\n",maxst.top());
        }
    }
    
    return 0;
}