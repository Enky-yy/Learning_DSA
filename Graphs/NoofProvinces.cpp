#include <bits/stdc++.h>

using namespace std;

void DFS(int node, vector<int> adjls[], int vis[])
{
    vis[node] = 1;

    for (auto it : adjls[node])
    {
        if (!vis[it])
            DFS(it, adjls, vis);
    }
}

int numOfProvinces(vector<vector<int>> adj, int V)
{
    vector<int> adjLs[V];
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (adj[i][j] == 1 && i != j)
            {
                adjLs[i].push_back(j);
                adjLs[j].push_back(i);
            }
        }
    }
    int vis[V] = {0};
    int cnt = 0;
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            DFS(i, adjLs, vis);
            cnt++;
        }
    }
}

int main()
{

    return 0;
}