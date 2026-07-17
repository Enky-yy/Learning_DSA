#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    unordered_map<int, int> parent;

    // Function to find the ultimate parent of node x
    int find(int x) {
        // If x is not present, make it its own parent
        if (parent.find(x) == parent.end())
            parent[x] = x;

        // Path compression to optimize future finds
        if (x != parent[x])
            parent[x] = find(parent[x]);

        return parent[x];
    }

    // Function to connect two nodes
    void unite(int x, int y) {
        // Set parent of x's root to y's root
        parent[find(x)] = find(y);
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        DSU dsu;

        // Connect each stone's row and column (offset to avoid collision)
        for (auto& stone : stones) {
            dsu.unite(stone[0], stone[1] + 10001);
        }

        unordered_set<int> components;

        // Count unique connected components
        for (auto& stone : stones) {
            components.insert(dsu.find(stone[0]));
        }

        // Max stones removed = total stones - number of components
        return stones.size() - components.size();
    }
};

int main() {
    vector<vector<int>> stones = {
        {0, 0}, {0, 1}, {1, 0}, {1, 2}, {2, 1}, {2, 2}
    };

    Solution obj;
    cout << obj.removeStones(stones) << endl;
    return 0;
}
