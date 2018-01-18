#include <bits/stdc++.h>

using namespace std;

string findFirstRepeatingChar(string s) {
   map<string,int> mymap;
   int n = s.length();
   string firstRep="";
   for(int i=0;i<n;i++){
       string ch = s.substr(i,1);
       if(mymap[ch]==0){
           mymap[ch] = i+1;
           continue;
       }
       if(firstRep==""){
           firstRep=ch;
       }
       else {
           if(mymap[firstRep] > mymap[ch]){
               firstRep=ch;
           }
       }
       
   }
   return firstRep;
}

int main(){
  string s = "abcba";
  cout<<findFirstRepeatingChar(s);
  return 0;
}
