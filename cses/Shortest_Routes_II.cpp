#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
using pll = pair<ll, pair<int, int>>;
 
int main()
{
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<pair<int, ll>>> arr(n + 1);
    // for (int i = 0; i < m; i++)
    // {
    //     int a, b;
    //     ll wt;
    //     cin >> a >> b >> wt;
    //     arr[a].push_back({b, wt});
    //     arr[b].push_back({a, wt});
    // }
    vector<vector<ll>> dist(n + 1, vector<ll>(n + 1, LLONG_MAX));
    dist[1][1] = 0;
    for (int i = 1; i <= n; i++)
    {
        dist[i][i] = 0;
    }
 
    while (m--)
    {
        int a, b;
        ll c;
        cin >> a >> b >> c;
 
        dist[a][b] = min(dist[a][b], c);
        dist[b][a] = min(dist[b][a], c);
    }
 
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
 
            if (dist[i][k] == LLONG_MAX)
                continue;
 
            for (int j = 1; j <= n; j++)
            {
 
                if (dist[k][j] == LLONG_MAX)
                    continue;
 
                dist[i][j] = min(dist[i][j],
                                 dist[i][k] + dist[k][j]);
            }
        }
    }
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        if (dist[a][b] == LLONG_MAX || dist[b][a] == LLONG_MAX)
            cout << -1 << endl;
        else
            cout << abs(dist[b][a]) << endl;
    }
 
    return 0;
}

