#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, k, x;
        cin >> n >> k >> x;

        if (k > n)
        {
            cout << "NO" << endl;
        }
        else
        {
            long long small = k*(k+1)/2;
            long long largest = (n * (n + 1)) / 2 - ((n - k) * (n - k + 1)) / 2;;
            if (x >= small && x <= largest)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
    return 0;
}