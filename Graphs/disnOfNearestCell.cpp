#include <bits/stdc++.h>

using namespace std;
int calculation(int sr, int sc, int rr, int rc)
{
    return abs(sc - rc) + abs(sr - rr);
}

vector<vector<int>> Distance(vector<vector<int>> &adj)
{
    int n = adj.size();
    int m = adj[0].size();

    vector<vector<int>> vis(n, vector<int>(m, 0));
    vector<vector<int>> dis(n, vector<int>(m, 0));
    int min = INT_MAX;
    queue<pair<pair<int, int>, int>> q;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (adj[i][j] == 1)
            {
                q.push({{i, j}, 0});
                vis[i][j] = 1;
            }
            else
                vis[i][j] = 0;
        }
    }
    while (!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int steps = q.front().second;
        q.pop();
        dis[x][y]=steps;

        int delrow[4]= {1,0,-1,0};
        int delCol[4]= {0,1,0,-1};

        for (int i = 0; i < 4; i++)
        {
            int nrow = x + delrow[i];
            int ncol = y + delCol[i];

            if(nrow<m && nrow>=0 && ncol<n && ncol>=0 && vis[nrow][ncol]==0){
                vis[nrow][ncol]=1;
                q.push({{nrow, ncol},steps+1});
            }
        }
        
    }
    return dis;
    
}

int main()
{

    return 0;
}