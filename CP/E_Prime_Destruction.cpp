#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        int maxi = 0;

        for (auto &it : arr)
        {
            cin >> it;
            maxi = max(maxi, it);
        }

        vector<int> prime(maxi + 1);

        for (int i = 0; i <= maxi; i++)
            prime[i] = i;

        for (int i = 2; i * i <= maxi; i++)
        {
            if (prime[i] == i)
            {
                for (int j = i * i; j <= maxi; j += i)
                {
                    if (prime[j] == j)
                        prime[j] = i;
                }
            }
        }

        vector<ll> dp(maxi + 1, 0);
        ll ans = 0;

        for (int x = k + 1; x <= maxi; x++)
        {
            ll take = LLONG_MAX;
            int y = x;

            while (y > 1)
            {
                int p = prime[y];

                take = min(
                    take,
                    1LL + 1LL * p * dp[x / p]);

                while (y % p == 0)
                    y /= p;
            }

            dp[x] = take;
        }

        for (int x : arr)
        {
            ans += dp[x];
        }

        cout << ans << endl;
    }

    return 0;
}