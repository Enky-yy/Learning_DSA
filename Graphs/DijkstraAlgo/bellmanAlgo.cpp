#include <bits/stdc++.h>

using namespace std;

vector<int> Bellman(vector<vector<int>> &grid, int V, int S)
{

    vector<int> dis(V , 1e9);
    dis[S]=0;
    
    for (int i = 0; i < V-1; i++)
    {
        for(auto it : grid){
            int u = it[0];
            int v = it[1];
            int w = it[2];

            if(dis[u]!= 1e9 && dis[u] + w <dis[v]){
                dis[v] = dis[u] + w;
            }
        }
    }

    for(auto it : grid){
        int u = it[0];
        int v = it[1];
        int w = it[2];

        if(dis[u]!=1e9 && dis[u] + w < dis[v]){
            return {-1};
        }
    }

    return dis;
    
}

int main() {

	int V = 6;
	vector<vector<int>> edges(7, vector<int>(3));
	edges[0] = {3, 2, 6};
	edges[1] = {5, 3, 1};
	edges[2] = {0, 1, 5};
	edges[3] = {1, 5, -3};
	edges[4] = {1, 2, -2};
	edges[5] = {3, 4, -2};
	edges[6] = {2, 4, 3};

	int S = 0;
	vector<int> dist = Bellman( edges,V, S);
	for (auto d : dist) {
		cout << d << " ";
	}
	cout << endl;

	return 0;
}