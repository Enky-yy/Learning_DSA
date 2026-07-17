#include <bits/stdc++.h>

using namespace std;

int minEffort(vector<vector<int>> &height)
{
    pair<int, int> src = {0, 0};
    int n = height.size();
    int m = height[0].size();
    pair<int, int> tar = {n - 1, m - 1};

    priority_queue<pair<int, pair<int, int>>> pq;
    vector<vector<int>> efforts(n, vector<int>(m, 1e9));
    efforts[src.first][src.second] = 0;
    pq.push({0, {src.first, src.second}});

    int delrow[4] = {1, 0, -1, 0};
    int delcol[4] = {0, -1, 0, 1};

    while (!pq.empty())
    {
        auto it = pq.top();
        int row = it.second.first;
        int col = it.second.second;
        int steps = it.first;
        int effortSrc = height[row][col];
        if (row == n - 1 && col == n - 1)
            return steps;
        for (int i = 0; i < 4; i++)
        {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            int effortNext = height[nrow][ncol];

            if (nrow < n && nrow >= 0 && ncol < m && ncol >= 0)
            {
                int newEffort = max(abs(effortNext - effortSrc), efforts[nrow][ncol]);
                if (newEffort < efforts[nrow][ncol])
                    efforts[nrow][ncol] = newEffort;
                pq.push({newEffort, {nrow, ncol}});
            }
        }
    }
    return efforts[tar.first][tar.second];
}

int main()
{

    return 0;
}