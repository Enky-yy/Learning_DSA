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
        string s;
        cin >> s;

        map<char, long long> freq;
        long long count = 0;
        vector<long long> a(n, 0);

        for (long long i = 0; i < n; i++)
        {
            freq[s[i]]++;
            if (freq[s[i]] == 1)
            {
                count++;
            }
            a[i] = count;
        }
        long long ans = 0;
        for (long long i = 0; i < n; i++)
        {
            ans += a[i];
        }
        cout << ans << endl;
    }

    return 0;
}