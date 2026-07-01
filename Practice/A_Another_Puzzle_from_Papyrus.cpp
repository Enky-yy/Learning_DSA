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
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        long long maxi = INT_MAX;
        long long ans = maxi;
        bool ok = true;
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] < b[i])
            {
                ok = false;
                break;
            }
            sum += (a[i] - b[i]);
        }

        if (ok)
            ans = sum;

        // cout<<time1<<endl;
        ok = true;
        sum = c;
        vector<long long> a1 = a, b1 = b;
        sort(a1.begin(), a1.end());
        sort(b1.begin(), b1.end());
        for (int i = 0; i < n; i++)
        {
            if (a1[i] < b1[i])
            {
                ok = false;
                break;
            }

            sum += (a1[i] - b1[i]);
        }
        if (ok)
            ans = min(ans, sum);
        if (ans == maxi)
            cout << -1 << '\n';
        else
            cout << ans << '\n';
    }

    return 0;
}