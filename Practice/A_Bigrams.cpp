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

        long long count = 0;
        bool three = false;
        for (long long i = 0; i < n; i++)
        {
            if (a[i] >= 2)
                count++;
            if (a[i] >= 3)
                three = true;
        }
        if (count >= 2 || three)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}