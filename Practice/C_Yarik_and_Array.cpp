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
        long long ans = INT_MIN;
        long long sum = 0;
        

        int i = 0;
        int j = 0;
        while (j < n)
        {
            if (sum < 0)
            {
                sum = 0;
                i = j;
            }
            if (i < j)
            {
                if ((a[j] ^ a[j - 1]) & 1)
                    sum += a[j];
                else
                {

                    sum = a[j];
                    i = j;
                }
            }
            else
            {
                sum = a[j];
            }
            ans = max(sum, ans);
            j++;
        }
        cout << ans << endl;
    }

    return 0;
}