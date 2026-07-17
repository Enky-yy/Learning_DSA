#include <bits/stdc++.h>

using namespace std;
class DisJoint
{

public:
    vector<int> rank, parent, size;

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

int operations(vector<vector<int>> &grid, int n)
{
    DisJoint ds(n);
    int cntExtras = 0;
    for (auto it : grid)
    {
        int u = it[0];
        int v = it[1];

        if (ds.findParent(u) == ds.findParent(v))
            cntExtras++;
        else
            ds.unionBySize(u, v);
    }
    int cntC = 0;
    for (int i = 0; i < n; i++)
    {
        if (ds.parent[i] == i)
            cntC++;
    }
    int ans = cntC - 1;

    if (cntExtras > cntC)
        return ans;
}

int main()
{

    return 0;
}