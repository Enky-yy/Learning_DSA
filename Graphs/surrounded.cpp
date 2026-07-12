#include <bits/stdc++.h>

using namespace std;

void DFS(int row, int col, vector<vector<char>> mat, vector<vector<int>> &vis, int delrow[], int delcol[])
{
    vis[row][col] = 1;

    int n = mat.size(), m = mat[0].size();
    // try 4 directions
    for (int k = 0; k < 4; k++)
    {
        // compute next cell
        int nrow = row + delrow[k], ncol = col + delcol[k];
        // check bounds and unvisited 'O'
        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && mat[nrow][ncol] == 'O')
        {
            // continue DFS
            DFS(nrow, ncol, mat, vis, delrow, delcol);
        }
    }
}

vector<vector<char>> surround(vector<vector<char>> adj)
{
    int n = adj.size();
    int m = adj[0].size();

    if (n == 0 || m == 0)
        return adj;

    int delrow[4] = {-1, 0, 1, 0};
    int delcol[4] = {0, 1, 0, -1};

    vector<vector<int>> vis(n, vector<int>(m, 0));
    for (int i = 0; i < m; i++)
    {
        if ((!vis[0][i]) && (adj[0][i] == 'O'))
            DFS(0, i, adj, vis, delrow, delcol);
        if (!vis[n - 1][i] && adj[n - 1][i] == 'O')
            DFS(n - 1, i, adj, vis, delrow, delcol);
    }
    for (int i = 0; i < n; i++)
    {
        if (!vis[i][0] && adj[i][0] == 'O')
            DFS(i, 0, adj, vis, delrow, delcol);
        if (!vis[i][m - 1] && adj[i][m - 1] == 'O')
            DFS(i, m - 1, adj, vis, delrow, delcol);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && adj[i][j] == 'O')
                adj[i][j] = 'X';

        }
    }
    return adj;
}

int main()
{

   vector<vector<char>> mat{
        {'X','X','X','X'},
        {'X','O','X','X'},
        {'X','O','O','X'},
        {'X','O','X','X'},
        {'X','X','O','O'}
    };
    
    vector<vector<char>> ans = surround(mat);
    for (int i = 0; i < (int)ans.size(); i++) {
        for (int j = 0; j < (int)ans[0].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}