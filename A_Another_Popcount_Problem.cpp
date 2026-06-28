#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;

    while (t--) {
        long long n, k;
        cin >> n >> k;

        long long ans = 0;
        long long total_remaining = n;

        for (long long i = 1; i <= total_remaining; i <<= 1) {
            long long count = min(k, total_remaining / i);
            ans += count;
            total_remaining -= count * i;

            if (count < k) break;
        }

        cout << ans << "\n";
    }

    return 0;
}