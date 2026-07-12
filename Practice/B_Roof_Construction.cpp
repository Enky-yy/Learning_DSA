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
        long long xorr = 0;
        long long maxi = 0;
        for (long long i = 0; i < n; i++)
        {
            xorr ^= i;
            maxi = max(maxi, xorr);
        }
        vector<long long> ans;
        if (maxi > n)
            maxi = n-1;
        for (long long i = 1; i < n; i++)
        {
            if (i != maxi)
                ans.push_back(i);
            else
            {
                ans.push_back(0);
                ans.push_back(maxi);
            }
        }

        for (auto it : ans)
            cout << it << " ";
        cout << endl;
    }

    return 0;
}