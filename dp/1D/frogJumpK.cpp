#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll ways(ll n, vector<ll> &dp, vector<ll> height, ll k)
{
    if (n == 0)
        return 0;
    if (dp[n] != 1e9)
        return dp[n];
    for (ll i = 0; i < k; i++)
    {
        ll jump = INT_MAX;
        if(n>i){
        jump = ways(n - i - 1,dp , height,k ) + abs(height[n] - height[n - i - 1]);
        dp[n] = min(jump, dp[n]);}
    }
    return dp[n];
}

int main()
{
    ll n = 5;
    ll k = 2;
    vector<ll> height = {10, 5, 20, 0, 15};
    vector<ll> dp(n, 1e9);
    cout << ways(n - 1, dp, height, k) << endl;
    return 0;
}