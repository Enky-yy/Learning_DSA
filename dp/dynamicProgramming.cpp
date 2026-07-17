#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll fib(ll n, vector<ll> &dp)
{
    if (n <= 1)
        return n;
    if (dp[n] != -1)
        return dp[n];
    dp[n] = (fib(n-1 , dp) + fib(n-2,dp));
    return dp[n];
}

int main()
{
    ll n = 10;
    vector<ll> dp(n + 1,-1);
    
    cout<<fib(n, dp)<<endl;
    return 0;
}