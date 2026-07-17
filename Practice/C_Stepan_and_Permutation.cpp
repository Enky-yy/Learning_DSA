#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void Sorting(vector<ll> grid, ll n, ll x, ll y)
{
    vector<long long> vis(n + 1, -1);
    long long id = 0;

    for (ll i = 1; i <= n; i++)
    {
        if (vis[i] != -1)
            continue;
        queue<ll> q;
        q.push(i);
        vis[i] = id;

        while (!q.empty())
        {

            ll node = q.front();
            q.pop();

            ll del[4] = {node + x, node - x, node + y, node - y};

            for (ll it : del)
            {
                if (it >= 1 && it <= n && vis[it] == -1)
                {
                    vis[it] = id;
                    q.push(it);
                }
            }
        }
        id++;
    }

    bool check = true;
    for (ll i = 1; i <= n; i++)
    {
        if (vis[i] != vis[grid[i]])
        {
            check = false;
            break;
        }
    }

    cout << (check ? "YES" : "NO") << endl;
}

int main()
{

    ll t;
    cin >> t;
    while (t--)
    {
        ll n, x, y;
        cin >> n >> x >> y;
        vector<long long> grid(n + 1);
        for (ll i = 1; i <= n; i++)
        {
            cin >> grid[i];
        }

        Sorting(grid, n, x, y);
    }
    return 0;
}