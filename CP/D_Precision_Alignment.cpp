#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Lab
{
    ll a, b, c;
    ll sum;
};

bool solve(ll x, const vector<Lab> &arr, ll k)
{
    ll need = 0;

    for (auto &[a, b, c, sum] : arr)
    {

        if (sum >= x)
            continue;

        ll d = x - sum;

        if (a == b && b == c)
            return false;

        ll extra = 0;

        if (!(a <= b && b <= c))
        {
            extra = 0;
        }
        else
        {
            ll y = min(b - a, c - b);
            extra = 2 * y + 2;
        }

        need += d + extra;

        if (need > k)
            return false;
    }

    return true;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        ll k;
        cin >> n >> k;

        vector<Lab> arr(n);

        ll mini = LLONG_MAX;

        for (auto &[a, b, c, sum] : arr)
        {
            cin >> a >> b >> c;
            sum = a + b + c;
            mini = min(mini, sum);
        }

        ll low = mini;
        ll high = mini + k;

        while (low < high)
        {
            ll mid = low + (high - low + 1) / 2;

            if (solve(mid, arr, k))
                low = mid;
            else
                high = mid - 1;
        }

        cout << low << endl;
    }

    return 0;
}