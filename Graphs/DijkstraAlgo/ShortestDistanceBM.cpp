#include <bits/stdc++.h>

using namespace std;

int shortDistance(vector<vector<int>> grid, int V, int Srow, int scol, int trow, int tcol)
{
    queue<pair<int, pair<int, int>>> pq;
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> dis(n, vector<int>(m, 1e9));

    dis[Srow][scol] = 0;
    pq.push({0, {Srow, scol}});

    while (!pq.empty())
    {
        auto it = pq.front();
        int steps = it.first;
        int row = it.second.first;
        int col = it.second.second;
        pq.pop();

        int delrow[4] = {1, 0, -1, 0};
        int delcol[4] = {0, -1, 0, 1};
        if (row == trow && col == tcol)
        {
            return steps;
        }
        for (int i = 0; i < 4; i++)
        {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if (nrow < n && nrow >= 0 && ncol < m && ncol >= 0 && grid[nrow][ncol] == 1)
            {
                if (steps + 1 < dis[nrow][ncol])
                    dis[nrow][ncol] = steps + 1;
                    pq.push({steps+1, {nrow, ncol}});
            }
        }
    }
    return -1;
}

int main()
{

    return 0;
}