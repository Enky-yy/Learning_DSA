#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll solve(ll n, vector<ll> &dp, vector<ll> nums)
{
    if(n<0)
     return 0;
    if(n==0)
        return n;
    if(dp[n] != -1)
        return dp[n];
    ll pick = nums[n] + solve(n-2, dp,nums);
    ll notPick = solve(n-1 , dp ,nums);
    return dp[n] = max(pick, notPick);
}

int main()
{
    vector<ll> nums = {1, 2, 4};
    vector<ll> dp(nums.size(), -1);
    cout << solve(nums.size() - 1, dp, nums) << endl;
    return 0;
}