#include <bits/stdc++.h>

using namespace std;

int NeighbourAlgo(int n, int m, vector<vector<int>> grid, int threshold)
{
    vector<vector<int>> dis(m, vector<int>(m, 1e9));

    for (auto it : grid)
    {
        dis[it[0]][it[1]] = it[2];
        dis[it[1]][it[0]] = it[2];
    }

    for (int i = 0; i < n; i++)
    {
        dis[i][i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (dis[j][i] == 1e9 || dis[i][k] == 1e9)
                    continue;
                dis[j][k] = min(dis[j][k], dis[j][i] + dis[i][k]);
            }
        }
    }

    int cntCity = n;
    int cityNo = -1;

    for (int city = 0; city< n; city++)
    {
        int cities=n;
        for (int adjCity =0 ; adjCity<n ; adjCity++){
            if(dis[city][adjCity]<=threshold){
                cities++;
            }
            if(cntCity>cities){
                cntCity = cities;
                cityNo = city;
            }
        }
    }
    return cityNo;
    
}

int main()
{

    return 0;
}