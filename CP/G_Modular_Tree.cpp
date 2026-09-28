#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<ll> arr1(n), arr2(n);

        for (int i = 0; i < n; i++)
            cin >> arr1[i];

        for (int i = 0; i < n; i++)
            cin >> arr2[i];

        vector<vector<int>> adj(n);

        for (int i = 0; i < n - 1; i++)
        {
            int u, v;
            cin >> u >> v;
            u--;
            v--;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> order;
        vector<int> parents(n, -1);
        order.push_back(0);
        parents[0] = 0;

        for (int i = 0; i <order.size(); i++)
        {
            int node = order[i];

            for (int v : adj[node])
            {
                if (v == parents[node])
                    continue;
                order.push_back(v);
                parents[v] = node;
            }
        }

        vector<ll> greatest(n, 0);
        vector<ll> best(n);

        ll answer = 0;

        for (int i = n - 1; i >= 0; i--)
        {
            int node = order[i];

            ll x = 0;
            ll s = 0;

            bool check = false;

            for (int v : adj[node])
            {
                if (parents[v] != node)
                    continue;

                check = true;

                x = gcd(x, greatest[v]);
                s += arr1[v];
            }

            if (!check)
            {
                best[node] = arr1[node];
                greatest[node] = 0;
            }
            else
            {
                ll r = gcd(arr2[node], s);
                r = gcd(x, r);

                if (r == arr2[node])
                {
                    best[node] = arr1[node];
                    greatest[node] = 0;
                }
                else
                {
                    best[node] = arr2[node] - r + (arr1[node] % r);
                    greatest[node] = r;
                }
            }

            answer += best[node];
        }

        cout << answer << endl;
    }

    return 0;
}