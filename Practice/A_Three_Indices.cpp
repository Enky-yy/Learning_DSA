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
        vector<long long> a(n);
        for (long long i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        // long long low = n;
        // long long maxi = 0;
        // bool check1 = false;
        // for (long long i = 0; i < n - 2; i++)
        // {
        //     if ((a[i] < a[i + 1]) && (a[i + 1] > a[i + 2]))
        //     {

        //         maxi= max(maxi , a[i+1]);
        //         if (maxi == a[i+1])
        //         {
        //             low = i + 1;
        //             check1=true;
        //             break;
        //         }
        //     }
        // }
        // // cout << low << endl;
        // if (low > 0 && low < n - 1 )
        //     cout << "YES\n"
        //          << low << " " << low + 1 << " " << low + 2 << endl;
        // else
        //     cout << "NO" << endl;

        bool found = false;

        for (int i = 0; i < n - 2; i++)
        {
            if (a[i] < a[i + 1] && a[i + 1] > a[i + 2])
            {
                cout << "YES\n";
                cout << i + 1 << " " << i + 2 << " " << i + 3 << "\n";
                found = true;
                break;
            }
        }

        if (!found)
            cout << "NO\n";
    }

    return 0;
}