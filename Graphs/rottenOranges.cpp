#include <bits/stdc++.h>

using namespace std;

int porabgesRotten(vector<vector<int>> &grid)
{
    if (grid.empty())
        return 0;

    int n = grid.size();
    int m = grid[0].size();

    int days = 0;
    int total = 0;
    int cnts = 0;

    queue<pair<int, int>> q;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] != 0)
                total++;
            if (grid[i][j] == 2)
                q.push({i, j});
        }
    }

    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    while (!q.empty())
    {
        int k = q.size();

        cnts += k;
        while (k--)
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx < 0 || nx >= n || ny < 0 || ny >= n || grid[nx][ny] != 1)
                    continue;

                grid[nx][ny] = 2;
                q.push({nx, ny});
            }
        }
        if (!q.empty())
            days++;
    }
    return total == cnts ? days : -1;
}

int main()
{

    return 0;
}