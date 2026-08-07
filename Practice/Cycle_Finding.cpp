#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, ll>>> grid(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        ll wt;
        cin >> a >> b >> wt;
        grid[a].push_back({b, wt});
    }
    vector<int> parent(n + 1, -1);
    vector<ll> dis(n + 1, 0);

    int check = -1;

    for (int iter = 1; iter <= n; iter++)
    {
        check = -1;
        for (int i = 1; i <= n; i++)
        {
            for (auto it : grid[i])
            {
                int node = it.first;
                ll wt = it.second;

                if (wt + dis[i] < dis[node])
                {
                    dis[node] = wt + dis[i];
                    parent[node] = i;
                    check = node;
                }
            }
        }
    }

    if (check == -1)
    {
        cout << "NO" << endl;
        return 0;
    }

    for (int i = 0; i < n; i++)

        check = parent[check];
    vector<int> ans;

    int curr = check;
    do
    {
        ans.push_back(check);
        check = parent[check];
    } while ((curr != check));

    ans.push_back(check);

    reverse(ans.begin(), ans.end());
    cout << "YES" << endl;
    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}