#include <iostream>
using namespace std;
int main() {
/* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;
    cin>>t;
    while(t--){
        int a,b,c;
        cin>>a>>b>>c;
        if(a==b && b==c){
            cout<<"Equilateral"<<endl;
        }
        else if(a==b || b==c || a==c){
            cout<<"Isosceles"<<endl;
        }
        else{
            cout<<"None of these"<<endl;
        }   
          
    }

return 0;
}