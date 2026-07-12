#include <bits/stdc++.h>

using namespace std;

void DFS(int sr , int sc , vector<vector<int>>&copyy, vector<vector<int>> & adj, int newColor, int delrow[], int delCol[]){
    copyy[sr][sc]=newColor;
    int n = adj.size();
    int m = adj[0].size();
    for (int i = 0; i < 4; i++)
    {
        int nrow = i +delrow[i];
        int ncol = i + delCol[i];
        if(nrow>=0 && nrow<n && ncol<n && ncol>=0 && adj[nrow][ncol]==(newColor-1) && copyy[nrow][ncol]!=newColor){
            copyy[nrow][ncol]=newColor;
            DFS(nrow, ncol, copyy, adj, newColor, delrow, delCol);
        }
    }
    
}

vector<vector<int>> floodFilled(int sr, int sc , vector<vector<int>>&adj, int V){
    int iniColor = adj[sr][sc];
    vector<vector<int>> copyy = adj;

    int delRow[]= {-1,0,1,0};
    int delCol[]= {0,1,0,-1};
    
    DFS(sr, sc, copyy, adj, V, delRow, delCol);
    
}

int main() {
    
    return 0;
}