#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pll = pair<ll,int>;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, ll>>> arr(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        ll wt;
        cin >> a >> b >> wt;
        arr[a].push_back({b, wt});
    }
    vector<ll> dis(n + 1, LLONG_MAX);
    dis[1] = 0;
    priority_queue<pll, vector<pll>, greater<pll>> q;
    q.push({0, 1});

    while (!q.empty())
    {
        auto node = q.top();
        q.pop();
        int stop = node.second;
        ll wt = node.first;

        if(wt!=dis[stop])
            continue;

        for (auto it : arr[stop])
        {
            if ((wt + it.second) < dis[it.first])
            {
                dis[it.first] = (wt + it.second);
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