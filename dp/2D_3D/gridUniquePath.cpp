#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll solve(ll i, ll j, vector<vector<ll>> &dp)
{
    if (i == 0 || j == 0)
        return 1;
    if (i < 0 || j < 0)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    ll up = solve(i - 1, j, dp);
    ll left = solve(i, j - 1, dp);

    dp[i][j] = up + left;
    return dp[i][j];
}

int main()
{
    int m = 3;
    int n = 3;
    vector<vector<ll>> dp(m, vector<ll>(n, -1));
    cout << solve(m - 1, n - 1, dp) << endl;

    return 0;
}