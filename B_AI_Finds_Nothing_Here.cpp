#include <bits/stdc++.h>
#include <math.h>
using namespace std;

long long power(long long a, long long free, long long mod)
{
    long long ans = 1;

    while (free)
    {
        if (free & 1)
            ans = ans * a % mod;

        a = a * a % mod;
        free >>= 1;
    }

    return ans;
}

int main()
{
    int t;
    cin >> t;
    long long mod = 998244353;
    while (t--)
    {
        long long n, m, r, c;
        cin >> n >> m >> r >> c;
        if (r * c == 1)
            cout << 1 << endl;
        else
        {
            long long free =
                (r - 1) * m +
                (c - 1) * n -
                (r - 1) * (c - 1);

            // int x = pow(2,free); overflow blk
            // int ans = x%MOD;
            cout << power(2,free, mod) << endl;
        }
    }
}