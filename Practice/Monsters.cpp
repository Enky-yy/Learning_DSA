#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool dfs(const vector<vector<char>> &arr, vector<vector<int>> &vis, int nrow, int ncol, vector<vector<char>> &path, vector<vector<pair<int, int>>> &parent, int delrow[], int delcol[], char dict[], int n, int m)
{
    vis[nrow][ncol] = 1;

    for (int i = 0; i < 4; i++)
    {
        int row = nrow + delrow[i];
        int col = ncol + delcol[i];

        if (row >= n || row < 0 || col >= m || col < 0)
            continue;
        if (arr[row][col] != '.')
            continue;
        if (vis[row][col])
            continue;

        if (dfs(arr, vis, nrow, ncol, path, parent, delrow, delcol, dict, n, m) == true)
        {
            path[row][col] = dict[i];
            parent[row][col] = {nrow, ncol};
        }
    }
    return false;
}

using pii = pair<int, int>;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);

    queue<pii> q;
    vector<vector<int>> monsterDist(n, vector<int>(m, 1e9));
    vector<vector<int>> myDist(n, vector<int>(m, -1));

    pii start;

    for (int i = 0; i < n; i++)
    {
        cin >> grid[i];
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 'M')
            {
                q.push({i, j});
                monsterDist[i][j] = 0;
            }
            if (grid[i][j] == 'A')
            {
                start = {i, j};
            }
        }
    }

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};
    char dir[] = {'U', 'D', 'L', 'R'};
    while (!q.empty())
    {
        auto [r, c] = q.front();
        q.pop();

        for (int k = 0; k < 4; k++)
        {
            int nr = r + dr[k];
            int nc = c + dc[k];

            if (nr < 0 || nr >= n || nc < 0 || nc >= m)
                continue;
            if (grid[nr][nc] == '#')
                continue;
            if (monsterDist[nr][nc] != 1e9)
                continue;

            monsterDist[nr][nc] = monsterDist[r][c] + 1;
            q.push({nr, nc});
        }
    }
    queue<pii> bfs;

    bfs.push(start);
    myDist[start.first][start.second] = 0;

    vector<vector<pii>> parent(n, vector<pii>(m, {-1, -1}));
    vector<vector<char>> moveTaken(n, vector<char>(m));

    while (!bfs.empty())
    {
        auto [r, c] = bfs.front();
        bfs.pop();

        // Reached boundary
        if (r == 0 || r == n - 1 || c == 0 || c == m - 1)
        {
            cout << "YES\n";

            string ans;
            pii cur = {r, c};

            while (cur != start)
            {
                ans += moveTaken[cur.first][cur.second];
                cur = parent[cur.first][cur.second];
            }

            reverse(ans.begin(), ans.end());

            cout << ans.size() << '\n';
            cout << ans << '\n';
            return 0;
        }
        for (int k = 0; k < 4; k++)
        {
            int nr = r + dr[k];
            int nc = c + dc[k];

            if (nr < 0 || nr >= n || nc < 0 || nc >= m)
                continue;
            if (grid[nr][nc] == '#')
                continue;
            if (myDist[nr][nc] != -1)
                continue;

            int newTime = myDist[r][c] + 1;

            if (newTime >= monsterDist[nr][nc])
                continue;

            myDist[nr][nc] = newTime;
            parent[nr][nc] = {r, c};
            moveTaken[nr][nc] = dir[k];
            bfs.push({nr, nc});
        }
    }

    cout << "NO\n";

    return 0;
}