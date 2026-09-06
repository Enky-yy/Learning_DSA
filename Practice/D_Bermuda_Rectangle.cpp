#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        ll S;
        int q;
        cin >> S >> q;

        vector<ll> factors;

        for (ll i = 1; i * i <= S; i++)
        {
            if (S % i == 0)
            {
                factors.push_back(i);

                if (i != S / i)
                    factors.push_back(S / i);
            }
        }
        sort(factors.begin(), factors.end());

        vector<ll> left, right, m;
        ll r = 1;

        while (r <= S)
        {

            ll D = S / r;

            ll remain = S / D;

            int pos = (upper_bound(factors.begin(), factors.end(), D) - factors.begin()) - 1;

            ll p = factors[pos];

            left.push_back(r);

            right.push_back(remain);

            m.push_back(p);

            r = remain + 1;
        }
        ll K = left.size();

        vector<ll> PS(K + 1, 0);

        for (ll k = 0; k < K; k++)
        {
            PS[k + 1] = PS[k] + m[k] * (right[k] - left[k] + 1);
        }

        while (q--)
        {

            ll x, y;

            cin >> x >> y;

            int small_y = (lower_bound(right.begin(), right.end(), y) - right.begin());

            ll ans;
            if (m[small_y] >= x)
            {
                ans = x * y;
            }
            else
            {
                ll low = 0, high = K - 1, res = 0;

                while (low <= high)
                {

                    ll mid = low + (high - low) / 2;
                    if (m[mid] >= x)
                    {
                        res = mid;
                        low = mid + 1;
                    }
                    else
                        high = mid - 1;
                }

                ll k_star = res;

                ll r_star = right[k_star];

                ll greater_y = PS[small_y] + m[small_y] * (y - left[small_y] + 1);
                ll greater_r = PS[k_star + 1];
                ans = x * r_star + (greater_y - greater_r);
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}
