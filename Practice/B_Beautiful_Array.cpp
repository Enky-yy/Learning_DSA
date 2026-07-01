#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, k, b, s;
        cin >> n >> k >> b >> s;

        long long maxi = (k * b) + (k - 1) * n;
        long long mini = k * b;
        if (s > maxi || s < mini)
        {
            cout << -1 << endl;
            continue;
        }
        else
        {

            vector<long long> ans(n, 0);
            ans[0] = mini;

            long long extra = s-ans[0];
            long long add = min(extra , k-1);
            ans[0]+=add;
            extra-=add;


            for (int i = 1; i < n ; i++)
            {
                long long num = min(extra, k - 1);
                ans[i] = num;
                extra -= num;
            }

            for (int i = 0; i < n; i++)
            {
                cout << ans[i] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// using ll = long long;

// int main() {
//     int T;
//     cin >> T;

//     while (T--) {
//         ll n, k, b, s;
//         cin >> n >> k >> b >> s;

//         ll minSum = b * k;
//         ll maxSum = b * k + n * (k - 1);

//         if (s < minSum || s > maxSum) {
//             cout << -1 << '\n';
//             continue;
//         }

//         vector<ll> ans(n, 0);

//         ans[0] = b * k;

//         ll extra = s - ans[0];

//         ll add = min(extra, k - 1);
//         ans[0] += add;
//         extra -= add;

//         for (int i = 1; i < n; i++) {
//             add = min(extra, k - 1);
//             ans[i] += add;
//             extra -= add;
//         }

//         for (auto x : ans)
//             cout << x << " ";
//         cout << '\n';
//     }

//     return 0;
// }