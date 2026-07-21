#include <bits/stdc++.h>

using namespace std;
using ll = long long;
void dfs(const vector<vector<char>> &arr, vector<vector<int>> &vis, int row, int col, int n , int m)
{
    vis[row][col] = 1;
    int delrow[4] = {1, 0, -1, 0};
    int delcol[4] = {0, -1, 0, 1};
    for (int i = 0; i < 4; i++)
    {
        int nrow = delrow[i] + row;
        int ncol = delcol[i] + col;

        if (nrow < n && ncol < m && nrow >= 0 && ncol >= 0 && arr[nrow][ncol] == '.')
            if(!vis[nrow][ncol])
                dfs(arr, vis, nrow, ncol, n , m);

    }
}

int main()
{
    int n;
    int m;
    cin >> n >> m;
    vector<vector<char>> arr(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    vector<vector<int>> vis(n, vector<int>(m, 0));

    int count=0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(arr[i][j]=='#')
                continue;
            if(!vis[i][j] && arr[i][j]=='.'){
                count++;
                dfs(arr, vis , i , j , n , m);
            }
        }
    }
    cout<<count<<endl;
    

    return 0;
}