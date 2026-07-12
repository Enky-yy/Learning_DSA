#include <bits/stdc++.h>

using namespace std;

void dfs(int node, vector<int> adjs[], vector<int> vis)
{
    vis[node] = 1;
    for (auto it : adjs[node])
    {
        if (!vis[it])
            dfs(it, adjs, vis);
    }
}

int NoOfIslands(vector<vector<int>> adj, int V)
{
    vector<int> adjs[V];
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (adj[i][j] == 1 && i != j)
            {
                adjs[i].push_back(j);
                adjs[j].push_back(i);
            }
        }
    }
    int counts = 0;
    vector<int> vis(V, 0);
    int node = 0;
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            dfs(i, adjs, vis);
            counts++;
        }
    }

    return counts;
}

int main()
{

    int V = 5;

    // List of undirected edges
    vector<vector<int>> edges = {{0,1},{1,2},{3,4}};

    // Create solution object
    

    // Print the number of connected components
    cout << "Number of Connected Components: " 
         << NoOfIslands(edges, V) << endl;

    return 0;
}