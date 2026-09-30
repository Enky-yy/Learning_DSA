#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
    vector<int> inDegree(n + 1, 0);
    vector<int> ans;
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        for (int next : adj[i])
            inDegree[next]++;
    }

    for (int i = 1; i <= n; i++)
    {
        if (inDegree[i] == 0)
            q.push(i);
    }

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        ans.push_back(node);

        for (int it : adj[node])
        {
            inDegree[it]--;
            if (inDegree[it] == 0)
            {
                q.push(it);
            }
        }
    }
    if (ans.size() != n)
    {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}