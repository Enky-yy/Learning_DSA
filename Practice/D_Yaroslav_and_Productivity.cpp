#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    int t;
    cin >> t;

    while (t--) {
        ll n, m;
        cin >> n >> m;

        vector<ll> a(n + 1);
        for (ll i = 1; i <= n; i++)
            cin >> a[i];

        vector<ll> track(n + 1, 0);
        for (ll i = 0; i < m; i++) {
            ll temp;
            cin >> temp;
            track[temp] = 1;
        }

        vector<array<ll, 2>>DP(n + 2);

        if (track[n]) {
            DP[n][0] = a[n];
            DP[n][1] = -a[n];
        } else {
            DP[n][0] = a[n];
            DP[n][1] = INT_MIN;
        }

        for (int i = n - 1; i >= 1; i--) {
            for (int p = 0; p < 2; p++) {
                ll val = (p == 0 ? a[i] : -a[i]);

                if (track[i])
                    DP[i][p] = val + max(DP[i + 1][0], DP[i + 1][1]);
                else
                    DP[i][p] = val + DP[i + 1][p];
            }
        }

        ll ans = max(DP[1][0], DP[1][1]) ;

        cout << ans<<endl;
    }

    return 0;
}