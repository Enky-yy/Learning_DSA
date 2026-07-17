#include <bits/stdc++.h>

using namespace std;

vector<int> Dijkstra(vector<vector<int>> adj[], int V, int S)
{
    set<pair<int, int>> sett;
    vector<int> dist(V, 1e9);
    dist[S] = 0;
    sett.insert({dist[S], S});

    while (!sett.empty())
    {
        auto it = *(sett.begin());

        int node = it.second;
        int steps = it.first;
        sett.erase(it);

        for (auto it : adj[node])
        {
            int adjNode = it[0];
            int edgeW = it[1];

            if (steps + edgeW < dist[adjNode])
                if (dist[adjNode] != 1e9)
                    sett.erase({dist[adjNode], adjNode});

            dist[adjNode] = steps + edgeW;
            sett.insert({dist[adjNode], adjNode});
        }
    }
    return dist;
}

int main()
{

    return 0;
}