#include <bits/stdc++.h>

using namespace std;

int PrimsAlgo(vector<vector<int>> grid[], int n)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<int> vis(n, 0);
    pq.push({0, 0});
    vector<int> MST;
    int sum = 0;

    while (!pq.empty())
    {
        auto it = pq.top();
        int edgeW = it.first;
        int node = it.second;
        pq.pop();

        if (vis[node] == 1)
            continue;

        vis[node] = 1;
        sum += edgeW;

        for (auto it : grid[node])
        {
            int adjNode = it[0];
            int adjEW = it[1];
            if (!vis[adjNode])
                pq.push({it[1], it[0]});
        }
    }
    return sum;
}

int main()
{

    return 0;
}