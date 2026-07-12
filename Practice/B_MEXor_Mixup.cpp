#include <bits/stdc++.h>

using namespace std;

long long xorr(long long a)
{
    long long n = a % 4;
    if (n == 0)
        return a;
    else if (n == 1)
        return 1;
    else if (n == 2)

        return a+ 1;
    else
        return 0;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long a, b;
        cin >> a >> b;
        long long ans = xorr(a - 1);

        if (ans == b)
            cout << a << endl;
        else if ((ans ^ b )!= a)
        {
            cout << a + 1 << endl;
        }

        else
            cout << a + 2 << endl;
    }

    return 0;
}