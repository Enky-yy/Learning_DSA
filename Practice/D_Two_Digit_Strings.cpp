#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        string a, b;
        cin >> a >> b;

        long long n = a.size();
        long long m = b.size();

        vector<long long> oneA(n + 1, 0), oneB(m + 1, 0);

        for (long long i = 1; i <= n; i++)
        {
            oneA[i] = (oneA[i - 1] + (a[i - 1] - '0')) % 10;
        }

        for (long long j = 1; j <= m; j++)
        {
            oneB[j] = (oneB[j - 1] + (b[j - 1] - '0')) % 10;
        }

        if (oneA[n] != oneB[m])
        {
            cout << -1 << endl;
            continue;
        }

        vector<long long> pre(m + 1, 0);
        vector<long long> curr(m+1,0);

        for (long long i = 1; i <= n; i++)
        {
            for (long long j = 1; j <= m; j++)
            {
                if (oneA[i] == oneB[j])
                {
                    curr[j] = pre[j - 1] + 1;
                }
                else
                {
                    curr[j] = max(pre[j], curr[j - 1]);
                }
            }

            swap(pre, curr);
        }

        cout << pre[m] << endl;
    }

    return 0;
}