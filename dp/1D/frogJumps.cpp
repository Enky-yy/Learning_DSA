#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int ways(ll n,  vector<ll> &dp, const vector<ll> &height)
{
    if (n == 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];

    ll jumptwo = INT_MAX;
    ll jumpone = ways(n - 1, dp, height) + abs(height[n] - height[n - 1]);
    if (n > 1)
        jumptwo = ways(n - 2, dp, height) + abs(height[n] - height[n - 2]);
    dp[n] = min(jumptwo, jumpone);
    return dp[n];
}


int main()
{
    vector<ll> height{2, 1, 3, 5, 4};
    long long n = height.size();
    vector<ll> dp(n, -1);
    cout << ways(n-1, dp, height) << endl;

    return 0;
}