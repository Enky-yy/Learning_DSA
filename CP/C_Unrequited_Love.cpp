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

        vector<ll> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        vector<ll> sum(n - 4);
        unordered_map<ll, ll> freq;
        for (int i = 0; i + 4 < n; i++)
        {
            ll s = arr[i] + arr[i + 2] - arr[i + 4];
            sum[i] = s;
        }

        ll ans = 0;
        for (int i = 0; i < n - 4; i++)
        {

            ans += freq[sum[i]];

            freq[sum[i]]++;

            if (i >= 2 && sum[i] == sum[i - 2])
                ans--;

            if (i >= 4 && sum[i] == sum[i - 4])
                ans--;
        }

        cout << ans << endl;
    }

    return 0;
}
