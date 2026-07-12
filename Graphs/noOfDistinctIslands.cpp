#include <bits/stdc++.h>

using namespace std;

void dfs(int row, int col, vector<vector<int>> grid, vector<vector<int>> &vis, vector<pair<int, int>> &vec, int row0 , int col0)
{

    vis[row][col] = 1;

    vec.push_back({row-row0, col-col0});
    int delrow[4] = {1, 0, -1, 0};
    int delcol[4] = {0, -1, 0, 1};

    int n = grid.size();
    int m = grid[0].size();

    for (int i = 0; i < 4; i++)
    {
        int nrow = row + delrow[i];
        int ncol = col + delcol[i];

        if (nrow < n && nrow >= 0 && ncol < m && ncol >= 0 && !vis[nrow][ncol] && grid[nrow][ncol] == 1)
        {

            dfs(nrow, ncol, grid, vis, vec, row0, col0);
        }
    }
}

int distinctIslands(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    set<vector<pair<int, int>>> st;

    if (n == 0 || m == 0)
        return 0;

    vector<vector<int>> vis(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && grid[i][j] == 1)
            {
                vector<pair<int, int>> vec;
                dfs(i, j, grid, vis, vec, i ,j);
                st.insert(vec);
            }
        }
    }
    return st.size();
}

int main() {
    vector<vector<int>> grid = {
        {1, 1, 0, 0},
        {1, 1, 0, 0},
        {0, 0, 1, 1},
        {0, 0, 1, 1}
    };
    cout << distinctIslands(grid);
    return 0;
}