#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int CheapestFLight(int n, vector<vector<int>> &flights, int src, int dst, int K) {

        // Create the adjacency list to represent airports and flights as a graph
        vector<pair<int, int>> adj[n];
        for (auto it : flights) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        // Create a priority queue (min heap) for Dijkstra's algorithm
        priority_queue<pair<int, int>,
                        vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // Initialize the distance array and ways array
        vector<int> dist(n, 1e9), ways(n, 0);

        // Distance for the source node is 0
        dist[src] = 0;

        // There's 1 way to reach the source (itself)
        ways[src] = 1;

        // Push the source node with distance 0
        pq.push({0, src});

        // Define the modulo value for large numbers
        int mod = (int)(1e9 + 7);

        // Perform Dijkstra's algorithm
        while (!pq.empty()) {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            // Iterate through adjacent nodes
            for (auto it : adj[node]) {

                // Next destination node
                int adjNode = it.first;

                // Cost of the flight to the next destination
                int edW = it.second;

                // If a shorter path is found, update the distance and number of ways
                if (dis + edW < dist[adjNode]) {

                    // Update the distance
                    dist[adjNode] = dis + edW;

                    // Push the new node with updated distance
                    pq.push({dis + edW, adjNode});

                    // Copy the number of ways to the new node
                    ways[adjNode] = ways[node];
                }

                // If the same shortest path is found, update the number of ways
                else if (dis + edW == dist[adjNode]) {

                    // Increment the number of ways
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }

        // Return the number of ways to reach the last node modulo 10^9 + 7
        return ways[dst] % mod;
    }
};

int main() {

    // Driver Code
    int n = 7;

    // Define the edges (source, destination, weight)
    vector<vector<int>> edges = {{0, 6, 7}, {0, 1, 2}, {1, 2, 3}, {1, 3, 3}, {6, 3, 3},
                                {3, 5, 1}, {6, 5, 1}, {2, 5, 1}, {0, 4, 5}, {4, 6, 2}};

    Solution obj;

    // Call the method to count the number of shortest paths
    int ans = obj.CheapestFLight(n, edges, 0, 3, 1);

    // Output the result
    cout << ans << endl;

    return 0;
}