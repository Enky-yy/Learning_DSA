#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;

int main()
{

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, ll>>> adj(n + 1);

    while (m--)
    {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    vector<ll> dist(n + 1, LLONG_MAX);
    vector<ll> ways(n + 1, 0);
    vector<int> mn(n + 1, INT_MAX);
    vector<int> mx(n + 1, INT_MIN);

    priority_queue<pair<ll, int>,vector<pair<ll, int>>,greater<pair<ll, int>>>pq;

    dist[1] = 0;
    ways[1] = 1;
    mn[1] = 0;
    mx[1] = 0;

    pq.push({0, 1});

    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();

        if (d != dist[u])
            continue;

        for (auto [v, w] : adj[u])
        {
            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                ways[v] = ways[u];
                mn[v] = mn[u] + 1;
                mx[v] = mx[u] + 1;

                pq.push({dist[v], v});
            }
            else if (dist[v] == dist[u] + w)
            {
                ways[v] = (ways[v] + ways[u]) % MOD;
                mn[v] = min(mn[v], mn[u] + 1);
                mx[v] = max(mx[v], mx[u] + 1);
            }
        }
    }

    cout << dist[n] << " "
         << ways[n] << " "
         << mn[n] << " "
         << mx[n] << '\n';
}