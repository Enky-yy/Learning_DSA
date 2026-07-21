#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll solve(ll i, ll j, vector<vector<ll>> &dp,  vector<vector<ll>> grid)
{
    if (i < 0 || j < 0)
        return 1e9;
    if (i == 0 && j == 0)
        return grid[i][j];
    if (dp[i][j] != -1)
        return dp[i][j];

    ll up = solve(i - 1, j, dp, grid);
    ll left = solve(i, j - 1, dp, grid);

    dp[i][j] = grid[i][j] + min(left, up);
    return dp[i][j];
}

int main()
{
    vector<vector<ll>> grid = {{5, 9, 6}, {11, 5, 2}};
    ll n = grid.size();
    ll m = grid[0].size();
    vector<vector<ll>> dp(n, vector<ll>(m, -1));
    cout << solve(n - 1, m - 1, dp, grid) << endl;
    return 0;
}