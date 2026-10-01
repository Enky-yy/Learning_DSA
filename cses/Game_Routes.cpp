#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    vector<int> indegree(n + 1);

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
            if (--indegree[v] == 0)
                q.push(v);
        }
    }

    vector<int> dp(n + 1, 0);
    dp[1] = 1;

    for (int u : topo)
    {
        for (int v : adj[u])
        {
            dp[v] += dp[u];
            if (dp[v] >= MOD)
                dp[v] -= MOD;
        }
    }

    cout << dp[n] << '\n';

    return 0;
}
