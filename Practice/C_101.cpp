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

        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            b[i] = a[i];
        }

        int L = -1, R = -1;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == 1)
            {
                if (L == -1)
                    L = i;
                R = i;
            }
        }

        if (L == -1)
        {
            int lo = -1, hi = -1;
            for (int i = 0; i < n; i++)
            {
                if (a[i] == -1)
                {
                    if (lo == -1)
                        lo = i;
                    hi = i;
                }
            }
            if (lo != -1)
            {
                for (int i = 0; i < n; i++)
                {
                    if (a[i] == -1)
                        b[i] = 0;
                }
                b[lo] = 1;
                b[hi] = 1;
            }
        }
        else
        {

            int leftNeg = -1;
            for (int i = 0; i < L; i++)
            {
                if (a[i] == -1)
                {
                    if (leftNeg == -1)
                        leftNeg = i;
                    b[i] = 0;
                }
            }
            if (leftNeg != -1)
                b[leftNeg] = 1;

            int rightNeg = -1;
            for (int i = R + 1; i < n; i++)
            {
                if (a[i] == -1)
                {
                    rightNeg = i;
                    b[i] = 0;
                }
            }
            if (rightNeg != -1)
                b[rightNeg] = 1;

            for (int i = L + 1; i < R; i++)
            {
                if (a[i] == -1)
                    b[i] = 0;
            }
        }

        for (int i = 0; i < n; i++)
        {
            cout << b[i] << " ";
        }
        cout << endl;
    }

    return 0;
}