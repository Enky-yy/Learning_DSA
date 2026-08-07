#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<vector<int>> solve(vector<vector<int>> &matrix, int V)
{
    vector<vector<int>> grid = matrix;

    for (int i = 0; i < V; i++)
    {
        grid[i][i] = 0;
    }

    for (int k = 0; k < V; k++)
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                grid[i][j] = min(grid[i][j], grid[i][k] + grid[k][j]);
            }
        }
    }
}

int main()
{

    return 0;
}