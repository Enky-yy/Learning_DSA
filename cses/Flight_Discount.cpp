#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct State
{
    ll dist;
    int node;
    int used;

    bool operator>(const State &other) const
    {
        return dist > other.dist;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, ll>>> arr(n + 1);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        ll z;
        cin >> x >> y >> z;
        arr[x].push_back({y, z});
    }
    vector<vector<ll>> price(n + 1, vector<ll>(2, LLONG_MAX));
    price[1][0] = 0;
    priority_queue<State, vector<State>, greater<State>> pq;
    pq.push({0, 1, 0});

    while (!pq.empty())
    {
        auto [wt, node, used] = pq.top();
        pq.pop();

        if (wt != price[node][used])
            continue;

        for (auto it : arr[node])
        {

            if ((wt + it.second) < price[it.first][used])
            {
                price[it.first][used] = wt + it.second;

                pq.push({price[it.first][used], it.first, used});
            }
            if (!used)
            {

                if (price[it.first][1] > wt + it.second / 2)
                {
                    price[it.first][1] = wt + it.second / 2;
                    pq.push({price[it.first][1], it.first, 1});
                }
            }
        }
    }

    cout<< min(price[n][1], price[n][0])<<endl;

    return 0;
}