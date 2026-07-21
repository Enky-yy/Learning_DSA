#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, d;
        cin >> n >> d;
        vector<long long> a(n);
        for (long i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        vector<long long> prefixSum(3 * n + 1, 0);
        for (int i = 1; i < 3 * n; i++)
        {
            prefixSum[i + 1] = prefixSum[i] + a[i % n];
        }
        long long maxi = 0;
        for (int i = 0; i < n; i++)
        {
            long long l = n + i - d;
            long long r = n + i + d;
            long long sadness = prefixSum[r + 1] - prefixSum[l] - a[i];
            long long happiness = 2LL * d * a[i] - sadness;
            if (happiness > 0)
                maxi += happiness;
        }
        cout << maxi << endl;
    }

    return 0;
}