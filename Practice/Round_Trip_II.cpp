// #include <bits/stdc++.h>

// using namespace std;
// using ll = long long;

// bool dfs(const vector<vector<int>>&arr , vector<int>&parents , int node){

//     if()
// }

// int main() {
//     int n , m;
//     cin>>n>>m;
//     vector<vector<int>> arr(n+1);
//     for (int i = 0; i < m; i++)
//     {
//         int a , b;
//         cin>>a>>b;
//         arr[a].push_back(b);
//     }
//     vector<int>parents(n+1,-1);

//     for (int i = 1; i <=n; i++)
//     {
//         if(dfs(arr, parents, i)==false){
//             break;
//         }
//     }

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

bool dfs(int u, int p, vector<int> &par, vector<int> &vis, vector<int> &ans, const vector<vector<int>> &adj, vector<int> &pathvis)
{
    vis[u] = 1;
    pathvis[u] = 1;

    for (int v : adj[u])
    {

        if (!vis[v])
        {
            par[v] = u;
            if (dfs(v, u, par, vis, ans, adj, pathvis) == true)
                return true;
        }
        else if (pathvis[v])
        {
            ans.push_back(v);

            int cur = u;
            while (cur != v)
            {
                ans.push_back(cur);
                cur = par[cur];
            }

            ans.push_back(v);

            reverse(ans.begin(), ans.end());
            cout << ans.size() << '\n';
            for (int x : ans)
                cout << x << ' ';
            cout << '\n';

            return true;
        }
        // else
        // {
        // }
    }
    pathvis[u] = 0;
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<int> vis(n + 1, 0);
    vector<int> pathvis(n + 1, 0);
    vector<int> par(n + 1, -1);
    vector<int> ans;

    while (m--)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            if (dfs(i, -1, par, vis, ans, adj, pathvis) == true)
            {
                return 0;
            }
        }
    }

    cout << "IMPOSSIBLE\n";
}