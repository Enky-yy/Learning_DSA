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
        int a, b;
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    vector<int> groups(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        if(groups[i])
            continue;
        queue<int> q;
        q.push(i);
        groups[i] = 1;
        while (!q.empty())
        {
            auto it = q.front();
            q.pop();

            for (auto a : arr[it])
            {
                if (!groups[a])
                {
                    groups[a] = 3 - groups[it];
                    q.push(a);
                }
                else if ((groups[a] == groups[it]))
                {
                    cout << "IMPOSSIBLE" << endl;
                    return 0;
                }
            }
        }
    }

    for (int i = 1; i < groups.size(); i++)
    {
        cout << groups[i] << " ";
    }
    cout << endl;

    return 0;
}