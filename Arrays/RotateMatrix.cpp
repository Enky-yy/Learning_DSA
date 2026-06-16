#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void RotatemATRIX(vector<vector<int>> &mat){
    int n = mat.size();
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j < n; i++)
        {
            swap(mat[i][j] , mat[j][i]);
        }
        
    }
    for (int i = 0; i < n; i++)
    {
        reverse(mat[i].begin(), mat[i].end()); 
    }
    
    
}

int main() {
    
    return 0;
}