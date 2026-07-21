#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll solve(ll i, ll j, vector<vector<ll>> matrix, vector<vector<ll>> &dp)
{
    if (i < 0 || j < 0)
        return 0;
    if (i == 0 || j == 0)
        return 1;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (matrix[i][j] == 1)
        return 0;

    ll up = solve(i-1, j , matrix, dp);
    ll left = solve(i, j-1, matrix, dp);

    dp[i][j] = up + left;
    return dp[i][j];
}

int main()
{
    vector<vector<ll>> matrix = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<ll>> dp(n, vector<ll>(m, -1));
    cout << solve(n - 1, m - 1, matrix, dp) << endl;
    return 0;
}