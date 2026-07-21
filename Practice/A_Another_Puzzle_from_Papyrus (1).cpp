#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, c;
        cin >> n >> c;
        vector<long long> a(n), b(n);
        for (long long i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (long long i = 0; i < n; i++)
        {
            cin >> b[i];
        }

        long long maxi = INT_MAX;
        long long ans = maxi;
        long long sum = 0;
        bool check = true;

        for (long long i = 0; i < n; i++)
        {
            if (a[i] < b[i])
            {
                check = false;
                break;
            }
            sum += (a[i] - b[i]);
        }
        if (check)
            ans = sum;

        vector<long long> a1 = a, b1 = b;
        sort(a1.begin(), a1.end());
        sort(b1.begin(), b1.end());

        check = true;
        sum = c;
        for (long long i = 0; i < n; i++)
        {
            if (a1[i] < b1[i])
            {
                check = false;
                break;
            }
            sum += (a1[i] - b1[i]);
        }
        if (check)
            ans = min(sum, ans);

        if (ans != maxi)
            cout << ans << endl;
        else
            cout << -1 << endl;
    }

    return 0;
}