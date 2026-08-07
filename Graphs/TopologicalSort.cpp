#include <bits/stdc++.h>

using namespace std;

void DFS(vector<int> adj[], vector<int> &vis, stack<int> &s, int node)
{
    vis[node] = 1;

    for (auto it : adj[node])
    {
        if (!vis[it])
            DFS(adj, vis, s, it);
    }
    s.push(node);
}

vector<int> topo(vector<int> adj[], int V)
{
    vector<int> vis(V, 0);
    stack<int> st;

    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
            DFS(adj, vis, st, i);
    }
    vector<int> ans;
    while (!st.empty())
    {
        int typo = st.top();
        ans.push_back(typo);
        st.pop();
    }

    return ans;
}

vector<int> topoBFS(vector<int> adj[], int V)
{
    vector<int> inDegree(V);

    for (int i = 0; i < V; i++)
    {
        for (auto it : adj[i])
            inDegree[it]++;
    }
    vector<int> ans;
    queue<int> q;

    for (int i = 0; i < V; i++)
    {
        if (inDegree[i] == 0)
            q.push(i);
    }

    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        ans.push_back(t);

        for (auto it : adj[t])
        {
            inDegree[it]--;

            if (inDegree[it] == 0)
                q.push(it);
        }
    }
    return ans;
}

int main()
{

    return 0;
}