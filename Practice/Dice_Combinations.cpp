#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
#include <math.h>
int main()
{
    long n;
    cin >> n;
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int dice = 1; dice <= 6; dice++)
        {
            if (i - dice >= 0)
                dp[i] = (dp[i] + dp[i - dice]) % mod;
        }
    }

    cout << dp[n] << endl;
    return 0;
}