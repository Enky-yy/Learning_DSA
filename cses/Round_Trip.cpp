#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool dfs(const vector<vector<int>> &adj, vector<int> &parent, vector<int> &vis, int node, int p,vector<int> &ans)
{
    vis[node] = 1;

    for (auto it : adj[node])
    {
        if (it == p)
            continue;
        if (!vis[it])
        {
            parent[it] = node;
            if (dfs(adj, parent, vis, it, node,ans))
                return true;
        }
        else
        {
            ans.push_back(it);
            int curr = node;
            while (curr != it)
            {
                ans.push_back(curr);
                curr = parent[curr];
            }

            ans.push_back(curr);
            return true;
        }
    }
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<int> parent(n + 1, -1);
    vector<int> vis(n + 1, 0);

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<int> ans;

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {

            if (dfs(adj, parent, vis, i,-1, ans))
            {
                cout << ans.size() << '\n';
                for (int x : ans)
                    cout << x << ' ';
                cout << '\n';
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}