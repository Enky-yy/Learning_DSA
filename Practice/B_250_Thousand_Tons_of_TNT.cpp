#include <bits/stdc++.h>

using namespace std;
using ll = long long;
vector<ll> maxiMini(vector<ll> &arr, int i, int n)
{
    vector<ll> ans = {LLONG_MIN, LLONG_MAX};
    // int maxi = INT_MIN, mini = INT_MAX;
    ll sum = 0;
    for (int k = 0; k < n; k++)
    {
        sum += arr[k];
        if (k % i == (i - 1))
        {
            ans[0] = max(sum, ans[0]);
            ans[1] = min(sum, ans[1]);
            sum = 0;
        }
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<ll> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        if (n == 1)
        {
            cout << 0 << endl;
            continue;
        }
        ll best=0;
        for (int i = 1; i <=n; i++)
        {
            if (n % i == 0)
            {
                auto ans = maxiMini(arr, i, n);
                best = max(best , abs(ans[0]-ans[1]));
            }
        }
        cout << best<<endl;
    }

    return 0;
}