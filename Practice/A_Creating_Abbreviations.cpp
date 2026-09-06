#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        vector<string> words(n);
        vector<string> abb(m);
        bool available[26] = {};

        for (int i = 0; i < n; i++)
        {
            cin >> words[i];
            available[words[i][0] - 'a'] = true;
        }
        for (int i = 0; i < m; i++)
        {
            cin >> abb[i];
        }

        bool can = true;

        for (int i = 0; i < m; i++)
        {
            auto word = abb[i];
            for (char c : word)
                if (!available[c-'A'])
                {
                    can = false;
                    break;
                }
            if(!can)
                break;
        }

        cout<< (can ? "YES" : "NO") <<endl;
    }

    return 0;
}