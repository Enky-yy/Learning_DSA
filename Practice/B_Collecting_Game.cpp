#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        vector<pair<long long, int>> a(n);
        for (long long i = 0; i < n; i++)
        {
            cin >> a[i].first;
            a[i].second = i;
        }

        sort(a.begin(), a.end());
        vector<long long> prefixSum(n, 0);
        prefixSum[0] = a[0].first;
        for (long long i = 1; i < n; i++)
        {
            prefixSum[i] = prefixSum[i - 1] + a[i].first;
        }
        vector<long long> ans(n);

        for (int i = 0; i < n; i++)
        {
            int j = i;
            int found = i;
            while (j < n)
            {
                pair<long long, long long> temp = {prefixSum[j] + 1, 1e-100};
                long long idx = lower_bound(a.begin(), a.end(), temp) - a.begin();
                idx--;
                if (idx == j)
                    break;
                found += idx - j;
                j = idx;
            }
            ans[a[i].second] = found;
        }

        for (auto it : ans)
            cout << it << " ";
        cout << endl;
    }

    return 0;
}