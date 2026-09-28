#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string s;
        cin >> n >> s;

        if (s[0] == '1')
        {
            cout << count(s.begin(), s.end(), '0') << '\n';
            continue;
        }

        int curr = count(s.begin(), s.end(), '0');
        int prev = 0;
        int ans = n;

        for (int i = 1; i <= n; i++)
        {

            {
                if (s[i - 1] == '1')
                {
                    prev++;
                }
                else
                {
                    curr--;
                }
            }

            ans = min(ans, prev + curr);
        }

        cout << ans << endl;
    }

    return 0;
}