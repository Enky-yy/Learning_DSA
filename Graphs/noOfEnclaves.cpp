#include <bits/stdc++.h>

using namespace std;

void DFS(int row, int col, vector<vector<int>> mat, vector<vector<int>> &vis, int delrow[], int delcol[])
{
    vis[row][col] = 1;

    int n = mat.size();
    int m = mat[0].size();

    for (int i = 0; i < 4; i++)
    {
        int nrow = row + delrow[i];
        int ncol = col + delcol[i];

        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && mat[nrow][ncol] == 1)
            DFS(nrow, ncol, mat, vis, delrow, delcol);
    }
}

int enclaves(vector<vector<int>> grid)
{
    int n = grid.size();
    int m = grid[0].size();

    if (n == 0 || m == 0)
        return 0;

    vector<vector<int>> vis(n, vector<int>(m, 0));

    int delrow[4] = {1, 0, -1, 0};
    int delcol[4] = {0, -1, 0, 1};

    for (int i = 0; i < n; i++)
    {
        if (!vis[i][0] && grid[i][0] == 1)
            DFS(i, 0, grid, vis, delrow, delcol);
        if (!vis[i][m - 1] && grid[i][m - 1] == 1)
            DFS(i, m - 1, grid, vis, delrow, delcol);
    }
    for (int i = 0; i < m; i++)
    {
        if (!vis[0][i] && grid[0][i] == 1)
            DFS(0, i, grid, vis, delrow, delcol);
        if (!vis[n - 1][i] && grid[n - 1][i] == 1)
            DFS(n - 1, i, grid, vis, delrow, delcol);
    }

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1 && vis[i][j] == 0)
                cnt++;
        }
    }
    return cnt;
}

int main() {
    // Define the grid
    vector<vector<int>> grid{
        {0, 0, 0, 0},
        {1, 0, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0}
    };

    // Create Solution instance
    

    // Compute and print the number of enclaves
    cout << enclaves(grid) << endl; // Expected: 3
    return 0;
}

