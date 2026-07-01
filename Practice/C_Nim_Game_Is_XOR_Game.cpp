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
        vector<int> arr(n);
        long long total = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            total = total ^ arr[i];
        }
        if (n == 1)
        {
            cout << 0 << endl;
            continue;
        }
        long long count = 0;
        if(total == 0) count=1;
        else count =0;
        
        for (int i = 0; i < n; i++)
        {
            long bits = total ^ arr[i];
            if (bits < arr[i])
                count++;
        }
        cout << count % 998244353 << endl;
    }

    return 0;
}