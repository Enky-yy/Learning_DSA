#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n+1);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        arr[x].push_back(y);
        arr[y].push_back(x);
    }
    vector<int> vis(n + 1, 0);
    vector<int> teams(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
            continue;

        queue<int> q;

        q.push(i);
        vis[i] = 1;
        teams[i] = 1;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (auto it : arr[node])
            {
                if (!vis[it])
                {
                    vis[it] = 1;

                    // Opposite team
                    teams[it] = 3 - teams[node];

                    q.push(it);
                }
                else if (teams[it] == teams[node])
                {
                    cout << "IMPOSSIBLE" << endl;
                    return 0;
                }
            }
        }
    }

    for (int i = 1; i < teams.size(); i++)
    {
        cout << (teams[i])<< " ";
    }
    cout << endl;

    return 0;
}