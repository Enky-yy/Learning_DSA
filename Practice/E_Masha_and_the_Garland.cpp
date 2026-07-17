#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, q;
        cin >> n >> q;
        string s;
        cin >> s;
        while (q != 0)
        {

            long long l, r, k;
            cin >> l >> r >> k;
            long long zeros = 0;
            long long ones = 0;
            for (long long i = (l - 1); i < r; i++)
            {
                if (s[i] == '0')
                    zeros++;
                else
                    ones++;
            }
            long long difference = abs(ones - zeros);
            // cout<<difference<<endl;

            if (difference <= k)
                cout << "YES" << endl;
            else

                cout << "NO" << endl;
            q--;
        }
    }

    return 0;
}
