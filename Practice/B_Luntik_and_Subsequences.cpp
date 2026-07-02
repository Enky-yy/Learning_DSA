#include <bits/stdc++.h>
#include <math.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        vector<long long> a(n);
        long long ones = 0;
        long long zeros = 0;
        for (long long i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] == 1)
                ones++;
            else if (a[i] == 0)
                zeros++;
        }
        long long ans = ones * pow(2,zeros);
        cout<<ans<<endl;
    }

    return 0;
}