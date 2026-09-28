#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pll = pair<ll, int>;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, ll>>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        ll z;
        cin >> x >> y >> z;
        adj[x].push_back({y, z});
    }

    vector<ll> dis(n + 1, LLONG_MAX);

    priority_queue<pll, vector<pll>, greater<pll>> q;
    dis[1] = 0;
    q.push({0, 1});

    while (!q.empty())
    {
        auto [d, n] = q.top();
        q.pop();

        if (dis[n] != d)
        {
            continue;
        }

        for (auto it : adj[n])
        {
            if (d + it.second < dis[it.first])
            {
                dis[it.first] = d + it.second;
                q.push({dis[it.first], it.first});
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << dis[i] << " ";
    }
    cout << endl;

    return 0;
}