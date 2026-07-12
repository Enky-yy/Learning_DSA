#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to detect cycle in a directed graph using Kahn's Algorithm
    bool hasCycle(int V, vector<vector<int>>& adj) {
        // Store in-degrees of all nodes
        vector<int> indegree(V, 0);
        for (int u = 0; u < V; u++) {
            for (int v : adj[u]) {
                indegree[v]++;
            }
        }

        // Queue for nodes with 0 in-degree
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        // Count visited nodes
        int count = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            count++;

            // Reduce in-degree of neighbors
            for (int neighbor : adj[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // If count != V, cycle exists
        return count != V;
    }
};

int main() {
    int V = 4;
    vector<vector<int>> adj = {
        {1}, {2}, {3}, {1}
    };

    Solution obj;
    if (obj.hasCycle(V, adj))
        cout << "Cycle detected\n";
    else
        cout << "No cycle\n";
    return 0;
}
