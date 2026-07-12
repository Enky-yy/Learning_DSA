#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


ll gameCost(ll x)
{
    int bits = 0, ones = 0;
    ll temp = x;

    while (temp)
    {
        bits++;
        ones += temp & 1;
        temp >>= 1;
    }

    return bits + ones - 1;
}

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<ll> a(n);
        for (ll &x : a)
            cin >> x;

        ll ans = LLONG_MAX;

        for (int k = 0; k <= 18; k++)
        {
            ll power = 1LL << k;
            ll total = k;

            for (ll x : a)
            {
                ll need = (x + power - 1) / power;
                ll best = LLONG_MAX;

                for (int j = 0; j <= 18; j++)
                {
                    ll step = 1LL << j;

                    ll cnt = ((need + step - 1) / step) * step;
                    if (cnt == 0)
                        cnt = step;

                    ll cur = cnt * power + gameCost(cnt);
                    best = min(best, cur);
                }

                total += best - x;
            }

            ans = min(ans, total);
        }

        cout << ans << '\n';
    }

    return 0;
}