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

vector<vector<string>> Merge(vector<vector<string>> adj)
{
    int n = adj.size();
    DisJoint ds(n);
    unordered_map<string, int> map;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < adj[i].size(); j++)
        {
            string mail = adj[i][j];
            if (map.find(mail) == map.end())
                map[mail] = i;
            else
                ds.unionBySize(i, map[mail]);
        }
    }

    vector<string> merged[n];
    for (auto it : map)
    {
        string mail = it.first;
        int place = ds.findParent(it.second);

        merged[place].push_back(mail);
    }
    vector<vector<string>> ans;

    for (int i = 0; i < n; i++)
    {
        if (merged[i].size() == 0)
            continue;
        sort(merged[i].begin(), merged[i].end());
        vector<string> temp;
        temp.push_back(adj[i][0]);
        for (auto it : merged[i])
            temp.push_back(it);

        ans.push_back(temp);
    }
    return ans;
}

int main()
{

    return 0;
}