#include <bits/stdc++.h>

using namespace std;


int main(){
    long n,q;
    ifstream inFile;
    inFile.open("input.txt");
    inFile >> n;
    inFile >> q;

    //scanf("%ld %ld",&n,&q);
    long lastAnswer = 0;
    vector<vector<long>> arr(n);


    while(q--) {
        long i,x,y,seq;
        inFile >> i;
        inFile >> x;
        inFile >> y;
        //scanf("%ld %ld %ld",&i,&x,&y);

        switch(i) {
            case 1:
                seq = (x ^ lastAnswer) % n;
                arr[seq].push_back(y);
                break;
            case 2:
                seq = (x ^ lastAnswer) % n;
                long size = arr[seq].size();
                lastAnswer = arr[seq][y%size];
                printf("%ld\n",lastAnswer); 
        }
    }
    
    return 0;
}