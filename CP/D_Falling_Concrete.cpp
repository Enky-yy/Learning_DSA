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
        cin >> n;

        vector<int> arr(n);

        int khuda = 0;

        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            arr[i] = x - (i + 1);
        }

        sort(arr.begin(), arr.end());

        int ans = 1;
        int curr = 1;

        for (int i = 1; i < n; i++)
        {
            if (arr[i] == arr[i - 1] + 1)
            {
                curr++;
            }
            else if (arr[i] != arr[i - 1])
            {
                curr = 1;
            }

            ans = max(ans, curr);
        }

        cout << ans << endl;
    }

    return 0;
}