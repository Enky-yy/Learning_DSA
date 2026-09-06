#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    int n;
    cin >> n;

    while (n--) {
        ll a, b;
        cin >> a >> b;

        if ((a + b) % 3 == 0 && max(a, b) <= 2 * min(a, b))
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}