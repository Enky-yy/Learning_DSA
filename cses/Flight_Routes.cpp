#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pll = pair<ll, int>;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<int, ll>>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    vector<ll> ans(n+1, 0);
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0, 1});
    while (!pq.empty())
    {
        auto data = pq.top();
        pq.pop();
        ll wt = data.first;
        int node = data.second;

        if (ans[node] >= k)
            continue;
        if (node == n)
        {
            cout << wt << " ";
        }
        ans[node]++;

        // if (ans.size() == int(k))
        //     break;

        for (auto it : adj[node])
        {
            if (wt + it.second < 2e14)
                pq.push({wt + it.second, it.first});
        }
    }

    // sort(ans.begin(), ans.end());
    // int i = 0;
    // while (i != c)
    // {
    //     cout << ans[i] << " ";
    //     i++;
    // }

    return 0;
}