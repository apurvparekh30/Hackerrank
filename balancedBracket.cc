#include <bits/stdc++.h>

using namespace std;


int main(){
    long n;
    ifstream inFile;
    inFile.open("input.txt");
    inFile >> n;
    //scanf("%ld",&n);
    while(n--) {
        string seq;
        inFile>>seq;
        //cin>>seq;
        long len = seq.length();
        stack <char> st;
        bool flag = true;
        for(int i=0;i<len;i++) {
            if(seq[i] == '(' || seq[i] == '{' || seq[i] == '[' )
                st.push(seq[i]);
            else {
                if(st.empty()) {
                    printf("NO\n");
                    flag = false;
                    break;
                }
                if(st.top() != seq[i] -1 && st.top() != seq[i] -2){
                    flag = false;
                    printf("NO\n");
                    break;
                }
                else {
                    st.pop();
                }
            }
        }
        if(flag && st.empty())
            printf("YES\n");
        else
            printf("NO\n");
    }
    
    return 0;
}