#include <bits/stdc++.h>

using namespace std;


int main(){
    int n;
    cin >> n;

    for(int i=n-1;i>=0;i--){
    	for(int j=i-1;j>=0;j--){
    		printf(" ");
    	}
    	for(int k=n-i;k>0;k--){
    		printf("#");
    	}
    	printf("\n");
    }
    return 0;
}
