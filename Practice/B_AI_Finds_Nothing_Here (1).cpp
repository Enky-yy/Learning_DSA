#include <bits/stdc++.h>

using namespace std;

const long long mod = 998244353;

long long modPow(long long a, long long free)
{
    long long ans = 1;
    while (free)
    {
        if (free & 1)
        {
            ans = ans * a % mod;
        }

        a = a * a % mod;
        free>>=1;
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, m, r, c;
        cin >> n >> m >> r >> c;

        if (r * c == 1)
        {
            cout << 1 << endl;
        }
        else
        {
            long long free = (r - 1) * m + (c - 1) * n - ((r - 1) * (c - 1));
            cout << modPow(2, free) << endl;
        }
    }

    return 0;
}