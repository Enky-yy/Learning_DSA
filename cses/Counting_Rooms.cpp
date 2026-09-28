#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void dfs(int i, int j, const vector<vector<char>> &arr, vector<vector<int>> &vis, int m, int x)
{
    vis[i][j] = 1;

    int delrow[4] = {1, 0, -1, 0};
    int delcol[4] = {0, -1, 0, 1};

    for (int n = 0; n < 4; n++)
    {
        int nrow = i + delrow[n];
        int ncol = j + delcol[n];
        if (nrow < m && nrow >= 0 && ncol < x && ncol >= 0 && arr[nrow][ncol] == '.')
        {
            if (!vis[nrow][ncol])
                dfs(nrow, ncol, arr, vis, m, x);
        }
    }
}

int main()
{
    int n, x;
    cin >> n >> x;
    vector<vector<char>> arr(n, vector<char>(x));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < x; j++)
        {
            cin >> arr[i][j];
        }
    }
    vector<vector<int>> vis(n, vector<int>(x, 0));
    int cnts = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < x; j++)
        {
            if (arr[i][j] == '#')
            {
                continue;
            }
            if (arr[i][j] == '.' && !vis[i][j])
            {
                cnts++;
                dfs(i, j, arr, vis, n, x);
            }
        }
    }
    cout << cnts << endl;

    return 0;
}