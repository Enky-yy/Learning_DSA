#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;

        vector<long long> a(n);
        for (long long i = 0; i < n; i++)
        {
            cin>>a[i];
        }
        

        vector<long long> c;
        long long i = 0;

        while (i < n) {
            long long j = i;
            while (j < n && a[j] == a[i])
                j++;
            c.push_back(j - i);
            i = j;
        }

        vector<long long> freq(n + 2, 0);

        for (long long it : c)
            freq[it]++;

        vector<long long> counts(n + 2, 0), sums(n + 2, 0);

        for (long long i = n; i >= 1; i--) {
            counts[i] = counts[i + 1] + freq[i];
            sums[i] = sums[i + 1] + 1LL * i * freq[i];
        }

        long long ans = 0;

        for (long long i = 1; i <= n; i++) {
            if (freq[i] == 0)
                continue;

            long long count = counts[i];
            long long sum = sums[i];

            long long difference = 1LL * k - sum;

            if (difference % count != 0)
                continue;

            long long s = difference / count;

            if (s + i - 1 >= 0)
                ans++;
        }

        cout << ans << endl;
    }

    return 0;
}