#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        int t=n;
        if(n<3){
        	cout<<"-1"<<endl;
        	continue;
        }
        while(n%3!=0 && n-5>=0){
        	n=n-5;
        }
        if(n%3==0){
        	for(int i=0;i<n;i++){
        	cout<<"5";
	        }
	        for(int i=n;i<t;i++){
	        	cout<<"3";
	        }
	        cout<<endl;
        }
        else if(t%5==0){
        	for(int i=0;i<t;i++){
        		cout<<"3";
        	}
        	cout<<endl;
        }
        else{
        	cout<<"-1"<<endl;
        }
        
    }
    return 0;
}
