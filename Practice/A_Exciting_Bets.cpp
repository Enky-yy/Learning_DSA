#include <bits/stdc++.h>

using namespace std;

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        long long a, b;
        cin >> a >> b;
        long long gcd = abs(b - a);
        if (gcd == 0)
            cout << 0 << " "<<0 << endl;
        else
        {
            long long moves = min(b % gcd, gcd - (b % gcd));

            cout << gcd << " " << moves << endl;
        }
    }

    return 0;
}