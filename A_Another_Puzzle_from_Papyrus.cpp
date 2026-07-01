
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, c;
        cin >> n >> c;

        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }

        int maxi = INT_MAX;
        int ans = maxi;

        bool check = true;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] < b[i]) {
                check = false;
                break;
            }
            sum += (a[i] - b[i]);
        }
        if (check) ans = sum;

        vector<int> a1 = a, b1 = b;
        sort(a1.begin(), a1.end());
        sort(b1.begin(), b1.end());

        check = true;
        sum = c;

        for (int i = 0; i < n; i++) {
            if (a1[i] < b1[i]) {
                check = false;
                break;
            }
            sum += (a1[i] - b1[i]);
        }

        if (check) ans = min(ans, sum);

        if (ans == maxi)
            cout << -1 << '\n';
        else
            cout << ans << '\n';
    }
}