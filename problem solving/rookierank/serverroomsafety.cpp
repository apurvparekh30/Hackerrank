#include <bits/stdc++.h>
using namespace std;

bool checkFromLeft(int n, vector<int> height,vector<int> position,bool fromleft) {
    int j=1;
    int total;
    for(int i=0;i<j;i++){
        if(fromleft){
            total=position[i]+height[i];
            while(position[j]<=total && j<n){
               j++;
            }
        }
        else{
            total=position[i]-height[i];
            while(position[j]>=total && j<n){
                j++;
            }
        }
        if(j==n){
            break;
        }
    }
    if(j==n){
        return true;
    }
    return false;
}
string checkAll(int n, vector <int> height, vector <int> position) {
    bool left=checkFromLeft(n,height,position,true);
    reverse(position.begin(),position.end());
    reverse(height.begin(),height.end());
    bool right=checkFromLeft(n,height,position,false);

    if(left && right)
        return "BOTH";
    if(left)
        return "LEFT";
    if(right)
        return "RIGHT";
    return "NONE";
}

int main() {
    int n;
    cin >> n;
    vector<int> position(n);
    for(int position_i = 0; position_i < n; position_i++){
       cin >> position[position_i];
    }
    vector<int> height(n);
    for(int height_i = 0; height_i < n; height_i++){
       cin >> height[height_i];
    }
    string ret = checkAll(n, height, position);
    cout << ret << endl;
    return 0;
}
