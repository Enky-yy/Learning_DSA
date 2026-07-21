// #include <bits/stdc++.h>

// using namespace std;
// using ll = long long;
// using pll = pair<ll, int>;

// int main()
// {
//     int n, m;
//     cin >> n >> m;
//     vector<vector<pair<int, ll>>> arr(n + 1);
//     for (int i = 0; i < m; i++)
//     {
//         int a, b;
//         ll x;
//         cin >> a >> b >> x;
//         arr[a].push_back({b, x});
//     }
//     vector<ll> score(n + 1, LLONG_MIN);
//     score[1] = 0;
//     priority_queue<pll> pq;
//     // queue<pll>pq;
//     pq.push({0, 1});

//     while (!pq.empty())
//     {
//         auto [wt, node] = pq.top();
//         pq.pop();

//         if (wt != score[node])
//             continue;
//         // if(score[node]==LLONG_MAX || score[node]==LLONG_MIN)
//         //     break;

//         for (auto it : arr[node])
//         {
//             ll club = wt + it.second;
//             int stop = it.first;
//             if (club > score[stop])
//             {
//                 score[stop] = club;
//                 pq.push({score[stop], stop});
//             }
//         }
//     }

//     if(score[n] == LLONG_MIN || score[n]==LLONG_MAX)
//         cout<<-1<<endl;
//     else
//         cout<<score[n]<<endl;


//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll INF = 4e18;

struct Edge {
    int u, v;
    ll w;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<Edge> edges;
    vector<vector<int>> adj(n + 1), rev(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b;
        ll x;
        cin >> a >> b >> x;

        edges.push_back({a, b, -x});

        adj[a].push_back(b);
        rev[b].push_back(a);
    }

    vector<int> reach1(n + 1), reachN(n + 1);

    auto dfs = [&](int s, vector<vector<int>> &g, vector<int> &vis) {

        stack<int> st;
        st.push(s);
        vis[s] = 1;

        while (!st.empty()) {
            int u = st.top();
            st.pop();

            for (int v : g[u]) {
                if (!vis[v]) {
                    vis[v] = 1;
                    st.push(v);
                }
            }
        }
    };

    dfs(1, adj, reach1);
    dfs(n, rev, reachN);

    vector<ll> dist(n + 1, INF);
    dist[1] = 0;

    for (int i = 1; i <= n - 1; i++) {
        for (auto e : edges) {

            if (dist[e.u] == INF)
                continue;

            if (dist[e.v] > dist[e.u] + e.w) {
                dist[e.v] = dist[e.u] + e.w;
            }
        }
    }

    for (auto e : edges) {

        if (dist[e.u] == INF)
            continue;

        if (dist[e.v] > dist[e.u] + e.w &&
            reach1[e.u] &&
            reachN[e.v]) {

            cout << -1 << '\n';
            return 0;
        }
    }

    cout << -dist[n] << '\n';
}