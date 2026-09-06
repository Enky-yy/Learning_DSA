#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &x : a)
            cin >> x;

        long long cnt0 = 0;
        for (int x : a)
            if (x == 0)
                cnt0++;

        if (cnt0 == 1)
        {
            cout << "NO"<<endl;
            continue;
        }

        if (cnt0 == 0)
        {
            cout << "YES"<<endl;
            string s(n, 'A');
            cout << s << "\n";
            continue;
        }

        vector<int> cntArr(n + 2, 0);
        for (int x : a)
        {
            if (x <= n)
                cntArr[x]++;
        }

        int m = 0;
        while (m <= n && cntArr[m] >= 2)
            m++;

        vector<int> seen(m, 0);
        string s(n, 'C');

        for (int i = 0; i < n; i++)
        {
            if (a[i] < m)
            {
                seen[a[i]]++;
                if (seen[a[i]] == 1)
                    s[i] = 'A';
                else if (seen[a[i]] == 2)
                    s[i] = 'B';
                else
                    s[i] = 'A';
            }
        }

        cout << "YES"<<endl;
        cout << s << endl;
    }

    return 0;
}