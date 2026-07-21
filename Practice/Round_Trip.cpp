// #include <bits/stdc++.h>

// using namespace std;
// using ll = long long;

// bool dfs(const vector<vector<int>> &arr, vector<int> &vis, int i, int &k, vector<int> &places)
// {
//     vis[i] = 1;
//     k++;
//     for (auto it : arr[i])
//     {
//         if (vis[it] && k < 2)
//             return false;
//         else if (vis[it] && k >= 2)
//         {
//             places.push_back(it);
//             return true;
//         }
//         if (!vis[it])
//             if (dfs(arr, vis, it, k, places) == false)
//                 return false;
//             else
//             {
//                 places.push_back(it);
//                 return true;
//             }
//     }
//     return false;
// }

// int main()
// {
//     int n, m;
//     cin >> n >> m;
//     vector<vector<int>> arr(n + 1);
//     for (int i = 0; i < m; i++)
//     {
//         int a, b;
//         cin >> a >> b;
//         arr[a].push_back(b);
//         arr[b].push_back(a);
//     }
//     vector<int> vis(n + 1, 0);
//     vector<int> places;
//     int k = 0;
//     for (int i = 1; i <= n; i++)
//     {
//         if (!vis[i])
//             if (dfs(arr, vis, i, k, places) == false)
//             {
//                 cout << "IMPOSSIBLE" << endl;
//                 return 0;
//             };
//     }
//     cout << places.size() << endl;
//     for (int i = places.size() - 1; i > 0; i++)
//     {
//         cout << places[i] << " ";
//     }
//     cout << endl;

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> adj;
vector<int> vis, par;
vector<int> ans;

bool dfs(int u, int p) {
    vis[u] = 1;                     

    for (int v : adj[u]) {

        if (v == p) continue;

        if (!vis[v]) {
            par[v] = u;
            if (dfs(v, u))
                return true;
        }
        else {
            // cycle found

            ans.push_back(v);

            int cur = u;
            while (cur != v) {
                ans.push_back(cur);
                cur = par[cur];
            }

            ans.push_back(v);

            reverse(ans.begin(), ans.end());

            return true;
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    adj.resize(n + 1);
    vis.assign(n + 1, 0);
    par.assign(n + 1, -1);

    while (m--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            if (dfs(i, -1)) {
                cout << ans.size() << '\n';
                for (int x : ans)
                    cout << x << ' ';
                cout << '\n';
                return 0;
            }
        }
    }

    cout << "IMPOSSIBLE\n";
}