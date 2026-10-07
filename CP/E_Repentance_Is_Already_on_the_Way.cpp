#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<ll> a(n), b(n);

        for (int i = 0; i < n; i++)
            cin >> a[i];

        for (int i = 0; i < n; i++)
            cin >> b[i];

        auto weight = [&](ll x, ll y)
        {
            return (x == y ? 2LL : 1LL);
        };

        ll cur = 0;

        for (int i = 0; i < n; i++)
        {

            if (i > 0)
                cur += weight(a[i], b[i - 1]);

            cur += weight(a[i], b[i]);
        }

        ll path = cur;

        for (int i = n - 2; i >= 0; i--)
        {

            cur += (weight(a[i], b[i + 1]) - weight(a[i], b[i]));
            path = max(path, cur);
        }

        cout << path << endl;
    }

    return 0;
}