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
        vector<long long> a(n), b(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        long long sum_a = 0;
        long long sum_b = 0;
        bool check = true;
        for (int i = 0; i < n; i++)
        {
            sum_a += a[i];
            sum_b += b[i];
            if (sum_a > sum_b)
            {
                check = false;
                break;
            }
        }

        // long long l = n;
        // long long r = 0;
        // for (long long i = 0; i < n; i++)
        // {
        //     if (a[i] != b[i])
        //     {
        //         l = min(l, i);
        //     }
        //     if (a[n - 1 - i] != b[n - 1 - i])
        //     {
        //         r = max(r, n - 1 - i);
        //     }
        // }

        // for (l; l <= r; l++)
        // {
        //     if (!check)
        //         break;
        //     for (long long i = l; i <= r; i++)
        //     {
        //         if ((i - l) % 2 == 0)
        //         {
        //             if (a[i] > b[i])
        //                 check = false;
        //         }
        //         if ((i - l) % 2 != 0)
        //         {
        //             if (a[i] > b[i])
        //                 check = false;
        //         };
        //     }
        // }
        if (check)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}