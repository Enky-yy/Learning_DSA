#include <bits/stdc++.h>

using namespace std;

vector<int> Dijkstra(vector<vector<int>> adj[], int V, int S)
// T = O(E log(V))
{

    priority_queue<pair<int, int>> pq;
    vector<int> dis(V, 1e9);
    dis[S] = 0;
    pq.push({dis[S], S});

    while (!pq.empty()) // T = O(V)
    {
        int steps = pq.top().first;
        int node = pq.top().second;
        pq.pop(); // T = O(log(heapsize))

        for (auto it : adj[node]) // T = O(ne)
        {
            int edgeWeight = it[1];
            int points = it[0];

            if (steps + edgeWeight < dis[points])
            {
                dis[points] = steps + edgeWeight;
                pq.push({steps + edgeWeight, points});
                // T = O(log(heapsize))
            }
        }
    }
    return dis;
}

int main()
{

    return 0;
}