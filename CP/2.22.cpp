#include <bits/stdc++.h>
using namespace std;

int main() {
    long long s, k, m;
    cin >> s >> k >> m;

    long long t = m - k;

    if (m % s == 0) {
        if (t > k) {
            cout << s << "\n";
        } else {
            cout << llabs(s - k) + llabs(m - k) << "\n";
        }
    } else if (t > k) {
        cout << 0 << "\n";
    } else if (k > m) {
        cout << 0 << "\n";
    } else if (t < k) {
        if (s < t) {
            cout << max(0LL, t - k) << "\n";
        } else if (s > t) {
            cout << max(0LL, k - t) << "\n";
        }
    }

    return 0;
}
