// #include <bits/stdc++.h>

// using namespace std;
// using ll = long long;

// int main()
// {
//     int n;
//     cin >> n;
//     if (n <= 2)
//     {
//         cout << "NO" << endl;
//         return 0;
//     }
//     vector<int> arr(n + 1);
//     arr[0] = 1;
//     vector<int> ans1;
//     vector<int> ans2;
//     int low = 1;
//     int high = n - 1;
//     int i = 1;
//     while (low <= n)
//     {

//         ans1.push_back(low);
//         arr[low] = 1;
//         low += i;
//         i++;
//     }
//     i = 1;
//     while (high > 0)
//     {
//         if (!arr[high])
//         {
//             ans2.push_back(high);
//             high -= i;
//             i++;
//         }
//     }
//     ll sum1 = accumulate(ans1.begin(), ans1.end(), 0);
//     ll sum2 = accumulate(ans2.begin(), ans2.end(), 0);
//     if (sum1 == sum2)
//     {
//         cout << "YES" << endl;
//         cout << ans1.size();
//         cout << endl;
//         for (int it : ans1)
//         {
//             cout << it << " ";
//         }
//         cout << endl;
//         cout << ans2.size() << endl;
//         reverse(ans2.begin(), ans2.end());
//         for (int it : ans2)
//         {
//             cout << it << " ";
//         }
//         cout << endl;
//     }
//     else
//     {
//         cout << "NO" << endl;
//     }
//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;

    long long total = n * (n + 1) / 2;

    if (total % 2 != 0) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";

    long long target = total / 2;
    vector<int> a, b;

    // Greedily put the largest possible number in the first set.
    for (long long x = n; x >= 1; --x) {
        if (x <= target) {
            a.push_back(x);
            target -= x;
        } else {
            b.push_back(x);
        }
    }

    cout << a.size() << '\n';
    for (int x : a)
        cout << x << ' ';
    cout << '\n';

    cout << b.size() << '\n';
    for (int x : b)
        cout << x << ' ';
    cout << '\n';

    return 0;
}