#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n + 1);
    queue<int> q;
    q.push(1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        arr[a].push_back(b);
    }
    ll count = 0;
    ll mod = 1e9 + 7;
    // vector<int> visits(n + 1, 0);

    // int ans = 0;
    // for (int i = 1; i <= n; i++)
    // {
    //     ans = max(ans, int(arr[i].size()));
    // }

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        if (node == n)
        {
            count = (count + 1) % mod;
        }

        for (auto it : arr[node])
        {
            // if (!visits[it])
            // {
            //     // visits[it]=1;
            //     q.push(it);
            // }
            q.push(it);
            //     else{

            //         count+= visits[it];
            //         visits[it]++;
            //     }
        }
    }
    cout << count % mod << endl;

    return 0;
}