#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n + 1);
    for (int i = 0; i < m; i++)
    {
        int from, to;
        cin >> from >> to;
        arr[from].push_back(to);
        arr[to].push_back(from);
    }
    vector<int> vis(n + 1, 0);
    queue<int> q;
    vector<int> parent(n + 1, -1);
    vis[1] = 1;
    q.push(1);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (auto it : arr[node])
        {
            if (!vis[it])
            {
                vis[it] = 1;
                q.push(it);
                parent[it] = node;
            }
        }
    }
    if (!vis[n])
        cout << "IMPOSSIBLE" << endl;
    else
    {
        vector<int> path;
        int curr = n;
        while (curr!=-1)
        {
            path.push_back(curr);
            curr = parent[curr];
        }
        cout<<path.size()<<endl;
        reverse(path.begin(), path.end());
        for(auto it : path){
            cout<<it<<" ";
        }
        cout<<endl;
    }

    return 0;
}