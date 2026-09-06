#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<ll> a(n);
        vector<ll> b(m);

        for (int i = 0; i < n; i++)
        {
            cin>>a[i];
        }
        for (int i = 0; i < m; i++)
        {
            cin>>b[i];
        }
        

        ll bea = a[0] + n;
        ll ver = b[0] + m;

        if (bea >= ver)
            cout << 1 << endl;
        else
            cout << 2 << endl;
    }

    return 0;
}