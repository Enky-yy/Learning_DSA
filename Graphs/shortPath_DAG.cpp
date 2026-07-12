#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    // Helper function to perform DFS-based Topological Sort
    void topoSort(int node, vector<pair<int, int>> adj[], vector<int> &vis, stack<int> &st) {

      // Mark the current node as visited
      vis[node] = 1;

      // Traverse all adjacent nodes
      for (auto it : adj[node]) {

        // Get the target node from the pair
        int v = it.first;

        // If the node is not visited, call DFS on it
        if (!vis[v]) {
          topoSort(v, adj, vis, st);
        }
      }

      // Push the current node onto the stack after visiting all neighbors
      st.push(node);
    }

  public:
    // Function to find the shortest paths from node 0 to all other nodes
    vector<int> shortestPath(int N, int M, vector<vector<int>> &edges) {

      // Create adjacency list for the graph
      vector<pair<int, int>> adj[N];
      
      // Fill the adjacency list with edges
      for (int i = 0; i < M; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];

        // Store (target node, weight)
        adj[u].push_back({v, wt});
      }

      // Initialize visited array to keep track of visited nodes
      vector<int> vis(N, 0);

      // Stack to store the topological order
      stack<int> st;

      // Call topoSort for all unvisited nodes
      for (int i = 0; i < N; i++) {
        if (!vis[i]) {
          topoSort(i, adj, vis, st);
        }
      }

      // Initialize the distance vector with infinity
      vector<int> dist(N);
      for (int i = 0; i < N; i++) {
        dist[i] = 1e9;
      }

      // Distance to the source node (0) is 0
      dist[0] = 0;

      // Process all nodes in topological order
      while (!st.empty()) {
        int node = st.top();
        st.pop();

        // Relax all outgoing edges from the current node
        for (auto it : adj[node]) {
          int v = it.first;
          int wt = it.second;

          // Update distance if a shorter path is found
          if (dist[node] + wt < dist[v]) {
            dist[v] = wt + dist[node];
          }
        }
      }

      // Replace all unreachable nodes' distances with -1
      for (int i = 0; i < N; i++) {
        if (dist[i] == 1e9) {
          dist[i] = -1;
        }
      }

      // Return the final distance array
      return dist;
    }
};

// Driver code
int main() {

  // Number of nodes and edges
  int N = 6, M = 7;

  // Edge list input
  vector<vector<int>> edges = {
    {0, 1, 2},
    {0, 4, 1},
    {4, 5, 4},
    {4, 2, 2},
    {1, 2, 3},
    {2, 3, 6},
    {5, 3, 1}
  };

  // Create object of Solution class
  Solution obj;

  // Call shortestPath function
  vector<int> ans = obj.shortestPath(N, M, edges);

  int n = ans.size();

  // Print the resulting shortest distances
  for (int i = 0; i < n; i++) {
    cout << ans[i] << " ";
  }

  return 0;
}
