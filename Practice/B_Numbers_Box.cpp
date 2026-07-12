#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, m;
        cin >> n >> m;
        vector<long long> a(n * m);
        long long sum = 0;
        long long mini = INT_MAX;
        long long nega = 0;
        for (long long i = 0; i < m * n; i++)
        {
            cin >> a[i];
            sum += abs(a[i]);
            if (a[i] < 0)
                nega++;
            mini = min(mini, abs(a[i]));
        }
        if (nega % 2 != 0)
            sum -= (2 * mini);
        cout << sum << endl;
    }

    return 0;
}