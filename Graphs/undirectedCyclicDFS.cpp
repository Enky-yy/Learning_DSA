#include <bits/stdc++.h>

using namespace std;

bool DFS(int node, int parent, vector<int> adj[], vector<int> &vis)
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if(!vis[it])
        {
            if (DFS(it, node, adj, vis))
                return true;
        }
        else if (it != parent)
        {
            return true;
        }
    }
    return false;
}

bool isCycle(int V, vector<int> adj[])
{
    // initialise them as unvisited
    vector<int> vis(V, 0);
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            if (DFS(i, -1, adj, vis))
                return true;
        }
    }
    return false;
}
int main()
{
    vector<int> adj[4] = {{}, {2}, {1, 3}, {2}};
    bool ans = isCycle(4, adj);
    if (ans)
        cout << "1\n";
    else
        cout << "0\n";
    return 0;
    return 0;
}