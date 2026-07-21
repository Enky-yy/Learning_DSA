#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pll = pair<ll, int>;

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
        int a, b;
        ll wt;
        cin >> a >> b >> wt;
        arr[a].push_back({b, wt});
    }
    vector<vector<ll>> prices(n + 1, vector<ll>(2, LLONG_MAX));

    prices[1][0] = 0;

    priority_queue<State,
                   vector<State>,
                   greater<State>>
        pq;
    pq.push({0, 1, 0});

    while (!pq.empty())
    {
        auto [wt, node, used] = pq.top();
        pq.pop();

        if (wt != prices[node][used])
            continue;

        for (auto it : arr[node])
        {

            if ((wt + it.second) < prices[it.first][used])
            {
                prices[it.first][used] = wt + it.second;

                pq.push({prices[it.first][used], it.first, used});
            }
            if (!used)
            {

                if (prices[it.first][1] > wt + it.second / 2)
                {
                    prices[it.first][1] = wt + it.second / 2;
                    pq.push({prices[it.first][1], it.first, 1});
                }
            }
        }
        // ll maxi = *max_element(prices.begin()+1 , prices.end());
    }
    cout << prices[n][1] << endl;

    return 0;
}
