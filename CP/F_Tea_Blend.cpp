#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    const int maximum = 1e6;

    vector<int> factor(maximum + 1);

    for (int i = 0; i <= maximum; i++)
        factor[i] = i;

    for (int i = 2; 1ll * i * i <= maximum; i++)
    {
        if (factor[i] == i)
        {
            for (int j = i * i; j <= maximum; j += i)
            {
                if (factor[j] == j)
                    factor[j] = i;
            }
        }
    }

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<int> arr(n);

        vector<vector<int>> store(n);

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];

            int x = arr[i];

            while (x > 1)
            {
                int counter = 0;
                int k = factor[x];

                while (x % k == 0)
                {
                    x /= k;
                    counter ^= 1;
                }

                if (counter)
                    store[i].push_back(k);
            }
        }

        map<vector<int>, ll> freq;

        for (int i = 0; i < n; i++)
            freq[store[i]]++;

        map<int, int> par;

        ll ans = 0;

        for (int j = 0; j < n; j++)
        {

            int x = arr[j];

            while (x > 1)
            {
                int k = factor[x];
                int counter = 0;

                while (x % k == 0)
                {
                    x /= k;
                    counter ^= 1;
                }

                if (counter)
                {
                    par[k] ^= 1;
                }
            }

            vector<int> prefix;

            for (auto &[k, odd] : par)
            {
                if (odd)
                    prefix.push_back(k);
            }

            ans += freq[prefix];
        }

        cout << ans << endl;
    }
}