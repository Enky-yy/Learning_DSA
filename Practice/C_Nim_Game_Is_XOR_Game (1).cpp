#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int MOD = 998244353;
        vector<int> arr(n);
        int xorrr = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            xorrr ^= arr[i];
        }

        if (n == 1)
        {
            cout << 0 << endl;
            continue;
        }

        long long count = 0;
        if(xorrr == 0) count=1;
        else count =0;

        for (int j = 0; j < n; j++)
        {
            int bits = xorrr ^ arr[j];
            if (bits < arr[j])
            {
                count++;
            }
        }

        cout << count % MOD << endl;
    }
    return 0;
}