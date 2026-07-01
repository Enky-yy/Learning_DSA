#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, k;
        cin >> n >> k;
        vector<long long> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        long long largest = 1;
        long long counter = 1;

        sort(a.begin(), a.end());

        for (int i = 1; i < n; i++)
        {
            if (a[i] - a[i - 1] <= k)
            {
                counter++;
                largest = max(largest, counter);
                continue;
            }
            
            counter = 1;
        }
        cout << n-largest << endl;
    }

    return 0;
}