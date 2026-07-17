#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll solve (ll n , vector<ll> &dp ,vector<ll> money){
    if(n<0)
        return 0;
    if(n==0)
        return n;
    if(dp[n]!=-1)
        return dp[n];
    ll pick = money[n] + solve(n-2)
}

int main() {
    vector<ll> money ={2,1,4,9};
    ll n = money.size();
    vector<ll> dp(n,-1);
    cout<<solve(n-1,dp, money);
    return 0;
}