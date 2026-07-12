#include <bits/stdc++.h>

using namespace std;

vector<int> BFS (int V , vector<int> adj[]){
    vector<bool> visited(V);
    visited[0]=true;
    queue<int> q;
    q.push(0);
    vector<int> bfs;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        bfs.push_back(node);
        for(auto it : adj[node]){
            if(visited[it]==false){
                q.push(it);
                visited[it]=true;
            }
        }
    }
    return bfs;
    
}

int main() {
    
    return 0;
}