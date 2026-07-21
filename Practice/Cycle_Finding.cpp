#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pll = pair<int, ll>;

bool dfs(int i, const vector<vector<pll>> &arr, vector<int> &vis, vector<int> &parent, ll &sum, vector<int> &s)
{
    vis[i] = 1;
    parent[i] = 1;
    for (auto it : arr[i])
    {
        int node = it.first;
        ll weight = it.second;

        sum += weight;

        if (!vis[node])
        {
            if (dfs(node, arr, vis, parent, sum, s) == true)
            {
                if (sum < 0)
                {
                    s.push_back(node);
                    return true;
                }
            }
        }
        else if (parent[node])
        {
            if (sum < 0)
            {
                s.push_back(node);
                return true;
            }
        }
        sum-=weight;
    }
    parent[i] = 0;
    
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, ll>>> arr(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        arr[a].push_back({b, c});
    }
    vector<int> parent(n + 1, 0);
    vector<int> vis(n + 1, 0);
    vector<int> s;

    for (int i = 1; i <= n; i++)
    {
        ll sum = 0;
        if (!vis[i])
            if (dfs(i, arr, vis, parent, sum, s) == true)
            {
                if (sum < 0)
                {
                    cout << "YES" << endl;
                    s.push_back(i);
                    reverse(s.begin(), s.end());
                    for (auto it : s)
                    {
                        cout << it << " ";
                    }
                    return 0;
                }
            }
    }
    cout << "NO" << endl;

    return 0;
}