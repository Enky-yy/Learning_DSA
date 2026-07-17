#include <bits/stdc++.h>

using namespace std;

class DisJoint
{
    vector<int> rank, parent, size;

public:
    DisJoint(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = i;
        }
    }

    int findParent(int k)
    {
        if (k == parent[k])
            return k;
        return parent[k] = findParent(parent[k]);
    }
    void unionByRank(int u, int v)
    {
        int upu = findParent(u);
        int upv = findParent(v);

        if (upv == upu)
            return;
        if (rank[upu] < rank[upv])
            parent[upu] = upv;
        else if (rank[upv] < rank[upu])
        {
            parent[upv] = upu;
        }
        else
        {
            parent[upv] = upu;
            rank[upu]++;
        }
    }
    void unionBySize(int u, int v)
    {
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

int spanningTree(vector<vector<int>> adj[], int V)
{
    vector<pair<int, pair<int, int>>> edges;
    for (int i = 0; i < V; i++)
    {
        for (auto it : adj[i])
        {
            int adjNode = it[0];
            int wt = it[1];
            int node = i;

            edges.push_back({wt, {node, adjNode}});
        }
    }
    DisJoint ds(V);

    sort(edges.begin(), edges.end());
    int mst = 0;
    for (auto it : edges)
    {
        int w = it.first;
        int u = it.second.first;
        int v = it.second.second;

        if (ds.findParent(u) != ds.findParent(v))
        {
            mst += w;
            ds.unionBySize(u,v);
        }
    }
    return mst;
}

int main()
{

    return 0;
}