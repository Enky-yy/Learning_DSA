#include <bits/stdc++.h>
using namespace std;

using ll = long long;

pair<int, int> bfs(int node, vector<vector<int>> &adj)
{
    int n = adj.size();

    vector<int> dis(n, -1);
    queue<int> q;

    q.push(node);
    dis[node] = 0;

    int durr = node;

    while (!q.empty())
    {
        int k = q.front();
        q.pop();

        if (dis[k] > dis[durr])
        {
            durr = k;
        }

        for (int v : adj[k])
        {
            if (dis[v] == -1)
            {
                dis[v] = dis[k] + 1;
                q.push(v);
            }
        }
    }

    return {durr, dis[durr]};
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<vector<int>> adj(n);

        for (int i = 0; i < n - 1; i++)
        {
            int u, v;
            cin >> u >> v;

            cout << "? " << u << " " << v << " " << d << endl;

            int response;
            cin >> response;

            if (response == -1)
                return 0;

            u--;
            v--;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        pair<int, int> pair1 = bfs(0, adj);
        int point1 = pair1.first;

        pair<int, int> pair2 = bfs(point1, adj);
        int point2 = pair2.first;
        int diameter = pair2.second;

        cout << point1 + 1 << " " << point2 + 1 << " " << diameter << endl;
    }

    return 0;
}