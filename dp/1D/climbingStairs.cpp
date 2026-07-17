#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll ways (ll n , vector<ll> &dp){
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int main() {
    ll n =4;
    vector<ll> dp(n+1, -1);
    cout<<ways(n, dp)<<endl;
    return 0;
}