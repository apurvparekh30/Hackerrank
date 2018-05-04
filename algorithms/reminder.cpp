#include <bits/stdc++.h>
using namespace std;
int main(){
	string s="abc";
	vector<string> operations;
	operations.push_back("0 0 L");
	operations.push_back("2 2 L");
	operations.push_back("0 2 R");	
	for(int i=0;i<operations.size();i++){
        int i1,i2;
        char ch;
        stringstream linestream(operations[i]);
        linestream>>i1;
        linestream>>i2;
        linestream>>ch;
        for(int j=i1;j<=i2;j++){
            if(ch=='L'){
                if(s[j]=='a'){
                    s[j]='z';
                }
                else{
                    s[j]--;
                }
            }
            else{
                if(s[j]=='z'){
                    s[j]='a';
                }
                else{
                    s[j]++;
                }
            }
        }
    
    }
    cout<<s;
    return 0;
}