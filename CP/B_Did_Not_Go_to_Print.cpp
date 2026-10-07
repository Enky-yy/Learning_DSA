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
        cin >> n;
        cin >> s;

        vector<int> mem;
        vector<int> vis(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            if (s[i - 1] == '1')
            {
                mem.push_back(i);
            }
            else if (s[i - 1] == '2')
            {

                if (!mem.empty())
                {
                    int docu = mem.back();
                    mem.pop_back();
                    vis[docu] = 1;
                }
                else
                {
                    vis[i] = 1;
                }
            }
            else
            {
                vis[i] = 1;
            }
        }

        vector<int> ans;

        for (int i = 1; i <= n; i++)
        {
            if (!vis[i])
            {
                ans.push_back(i);
            }
        }

        cout << ans.size() << endl;

        for (int x : ans)
        {
            cout << x << ' ';
        }

        cout << endl;
    }

    return 0;
}
