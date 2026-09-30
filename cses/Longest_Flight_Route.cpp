#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    vector<int> indegree(n + 1, 0);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        indegree[b]++;
    }

    queue<int> q;

    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    vector<int> topo;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        topo.push_back(u);

        for (int v : adj[u])
        {
            indegree[v]--;

            if (indegree[v] == 0)
                q.push(v);
        }
    }
    vector<int> dp(n + 1, -1);
    vector<int> parent(n + 1, -1);

    dp[1] = 1;

    for (int u : topo)
    {
        if (dp[u] == -1)
            continue;

        for (int v : adj[u])
        {
            if (dp[v] < dp[u] + 1)
            {
                dp[v] = dp[u] + 1;
                parent[v] = u;
            }
        }
    }

    if (dp[n] == -1)
    {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    vector<int> path;

    int cur = n;

    while (cur != -1)
    {
        path.push_back(cur);
        cur = parent[cur];
    }

    reverse(path.begin(), path.end());

    cout << path.size() << '\n';

    for (int city : path)
        cout << city << " ";

    cout << '\n';

    return 0;
}
