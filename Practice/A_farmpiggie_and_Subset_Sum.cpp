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

        vector<int> ans(n + 1);

        int even = 2;
        for (int i = 1; i <= n; i += 2)
        {
            ans[i] = even;
            even += 2;
        }

        int odd = 1;
        for (int i = 2; i <= n; i += 2)
        {
            ans[i] = odd;
            odd += 2;
        }

        for (int i = 1; i <= n; i++)
        {
            cout << ans[i] << " ";
        }
        cout<<endl;
    }
    return 0;
}