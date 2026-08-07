#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int oranges(vector<vector<int>> &grid)
{
    if (grid.empty())
        return 0;

    int n = grid.size();
    int m = grid[0].size();

    int days = 0;
    int totals = 0;
    int counts = 0;

    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] != 0)
                totals++;
            if (grid[i][j] == 2)
                q.push({i, j});
        }
    }

    while (!q.empty())
    {
        int k = q.size();
        counts += k;

        while (k--)
        {
            int delrow[] = {1, 0, -1, 0};
            int delcol[] = {0, -1, 0, 1};
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            // Check all 4 directions
            for (int i = 0; i < 4; ++i)
            {
                int nx = x + delrow[i]; // New x-coordinate
                int ny = y + delcol[i]; // New y-coordinate

                // Skip invalid coordinates or already rotten/empty cells
                if (nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] != 1)
                    continue;

                // Mark the fresh orange as rotten
                grid[nx][ny] = 2;

                // Add its position to the queue to process in the next minute
                q.push({nx, ny});
            }
        }
        if (!q.empty())
            days++;
    }
    return totals == counts ? days : -1;
}

int main()
{
    vector<vector<int>> v{{2, 1, 1}, 
                          {1, 1, 0}, 
                          {0, 1, 1}};
    
    // Call the function to calculate minimum time required
    int rotting = oranges(v);

    // Output the result
    cout << "Minimum Number of Minutes Required " << rotting << endl;


    return 0;
}