#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> arr(n, vector<char>(m));
    pair<int, int> start, end;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];

            if (arr[i][j] == 'A')
                start = {i, j};

            if (arr[i][j] == 'B')
                end = {i, j};
        }
    }
    queue<pair<int, int>> q;
    vector<vector<int>> vis(n, vector<int>(m, 0));
    vector<vector<pair<int, int>>> parent(
        n, vector<pair<int, int>>(m, {-1, -1}));
    vector<vector<char>> path(n, vector<char>(m));
    q.push(start);
    vis[start.first][start.second] = 1;

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};
    char dir[] = {'U', 'D', 'L', 'R'};

    while (!q.empty())
    {

        auto [r, c] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {

            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr < 0 || nr >= n || nc < 0 || nc >= m)
                continue;

            if (vis[nr][nc])
                continue;

            if (arr[nr][nc] == '#')
                continue;

            vis[nr][nc] = 1;

            parent[nr][nc] = {r, c};

            path[nr][nc] = dir[i];

            q.push({nr, nc});
        }
    }

    if (!vis[end.first][end.second])
    {
        cout << "NO";
        return 0;
    }

    string ans;

    pair<int, int> cur = end;

    while (cur != start)
    {

        ans += path[cur.first][cur.second];

        cur = parent[cur.first][cur.second];
    }
    reverse(ans.begin(), ans.end());
    cout<<"YES"<<endl;
    cout << ans.size() << "\n";
    cout << ans << "\n";

    return 0;
}