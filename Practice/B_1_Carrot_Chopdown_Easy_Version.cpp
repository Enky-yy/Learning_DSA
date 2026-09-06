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

        vector<int> freq(k + 1);

        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            freq[x]++;
        }

        vector<int> countss(k + 2, 0);

        for (int i = k; i >= 1; i--)
        {
            countss[i] = countss[i + 1] + freq[i];
        }

        int ans = 0;

        for (int i = 1; i <= k; i++)
        {
            int curr = countss[i];

            if (2 * i <= k)
            {
                curr += freq[2 * i];
            }

            ans = max(ans, curr);
        }

        cout << ans << endl;
    }

    return 0;
}