#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    if (n <= 4)
    {
        cout << 0 << endl;
    }
    else
    {
        ll cntFive = 0;
        for (int i = 5; i <= n; i*=5)
        {
            ll k = n/i;
            cntFive+=k;
        }

        cout << cntFive << endl;
    }

    return 0;
}