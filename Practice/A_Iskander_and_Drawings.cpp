#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin>>n;
        string s;
        cin >> s;
        long long lineCnts = 0;
        long long maxi = 0;
        for (long long i = 0; i < n; i++)
        {
            if (s[i] == '#')
            {
                lineCnts++;
            }
            else
            {
                lineCnts=0;
            }
            maxi = max(maxi, lineCnts);
        }
        long long ans = (maxi+1) / 2;
        cout << ans << endl;
    }

    return 0;
}