#include <bits/stdc++.h>

using namespace std;

bool DFS(int node, vector<int> adj[], vector<int> &vis, vector<int> &pathVis)
{
    vis[node] = 1;
    pathVis[node] = 1;

    for (auto it : adj[node])
    {
        if (!vis[it]) // ignore
        {
            if (DFS(it, adj, vis, pathVis) == true)

                return true;
        }
        else if (pathVis[it])
        {
            return true;
        }
    }
    pathVis[node] = 0;
    return false;
}

bool cyclic(int n, vector<int> adj[])
{
    vector<int> vis(n, 0);
    vector<int> pathVis(n, 0);

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
            if (DFS(i, adj, vis, pathVis) == true)
            {
                return true;
            }
    }
    return false;
}

int main()
{

    // V = 11, E = 11;
    vector<int> adj[11] = {{}, {2}, {3}, {4, 7}, {5}, {6}, {}, {5}, {9}, {10}, {8}};
    int V = 11;
    bool ans = cyclic(V, adj);

    if (ans)
        cout << "True\n";
    else
        cout << "False\n";

    return 0;
}