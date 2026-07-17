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

bool isValid(int adjr, int adjc, int n, int m)
{
    return adjr >= 0 && adjr < n && adjc >= 0 && adjc < m;
}

vector<int> Queries(vector<vector<int>> operations)
{
    int n = operations.size();
    int m = operations[0].size();
    DisJoint ds(n * m);

    int vis[n][m];
    memset(vis, 0, sizeof vis);
    int cnts = 0;
    vector<int> ans;
    int delrow[4] = {1, 0, -1, 0};
    int delcol[4] = {0, -1, 0, 1};

    for (auto it : operations)
    {
        int row = it[0];
        int col = it[1];
        if (vis[row][col] == 1)
        {
            ans.push_back(cnts);
            continue;
        }
        vis[row][col] = 1;
        cnts++;
        for (int i = 0; i < 4; i++)
        {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if (isValid(nrow, ncol, n, m))
            {
                if (vis[nrow][ncol] == 1)
                {
                    int value = nrow * m + col;
                    if (ds.findParent(value) != ds.findParent(row * m + col))
                    {
                        cnts--;

                        ds.unionByRank(row * m + col, value);
                    }
                }
            }
        }
        ans.push_back(cnts);
    }

    return ans;
}

int main()
{

    return 0;
}