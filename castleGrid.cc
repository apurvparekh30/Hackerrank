#include <bits/stdc++.h>

using namespace std;

int minimumMoves(vector <string> grid, int startX, int startY, int goalX, int goalY,int n) {
    // Complete this function
    vector<vector<int>> v(n,vector<int>(n));
    vector<vector<int>> t(n,vector<int>(n));
    queue< pair<int,int> > q;
    q.push(make_pair(startX,startY));
    v[startX][startY] = 1;
    while(v[goalX][goalY] == 0){
        pair<int,int> p = q.front();
        q.pop();
        int i=p.first;
        int j=p.second;
        int cost = t[i][j];
        for(int k=i+1,l=j;k<n;k++) {
            if(grid[k][l] == 'X'){
                break;
            }
            if(v[k][l] == 0){
                q.push(make_pair(k,l));
                v[k][l] = 1;
                t[k][l] = cost + 1;
            }
        }
        for(int k=i-1,l=j;k>=0;k--) {
            if(grid[k][l] == 'X'){
                break;
            }
            if(v[k][l] == 0){
                q.push(make_pair(k,l));
                v[k][l] = 1;
                t[k][l] = cost + 1;
            }
        }
        for(int k=i,l=j+1;l<n;l++){
            if(grid[k][l] == 'X'){
                break;
            }
            if(v[k][l] == 0){
                q.push(make_pair(k,l));
                v[k][l] = 1;
                t[k][l] = cost + 1;
            }
        }
        for(int k=i,l=j-1;l>=0;l--){
            if(grid[k][l] == 'X'){
                break;
            }
            if(v[k][l] == 0){
                q.push(make_pair(k,l));
                v[k][l] = 1;
                t[k][l] = cost + 1;
            }
        }
    }
    return t[goalX][goalY];
}

int main() {
    int n;
    cin >> n;
    vector<string> grid(n);
    for(int grid_i = 0; grid_i < n; grid_i++){
       cin >> grid[grid_i];
    }
    int startX;
    int startY;
    int goalX;
    int goalY;
    cin >> startX >> startY >> goalX >> goalY;
    int result = minimumMoves(grid, startX, startY, goalX, goalY,n);
    cout<<result;
    return 0;
}
