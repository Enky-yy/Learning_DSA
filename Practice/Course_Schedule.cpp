#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    vector<int> indegree(n + 1);

    while (m--) {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        indegree[b]++;
    }

    queue<int> q;

    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0)
            q.push(i);
    }

    vector<int> order;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        order.push_back(u);

        for (int v : adj[u]) {
            indegree[v]--;

            if (indegree[v] == 0)
                q.push(v);
        }
    }

    if ((int)order.size() != n) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    for (int x : order)
        cout << x << " ";

    cout << '\n';
}