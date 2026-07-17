#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        long long minSum = n * (n + 1) / 2;
        long long sum = 0;
        bool check = true;
        for (long long i = 0; i < n; i++)
        {
            sum += a[i];
            long long mini = (i + 1) * (i + 2) / 2;
            if (mini > sum)
            {
                check = false;
                break;
            }
        }

        if (!check)
            cout << "NO" << endl;
        else
        {   
            cout<<"YES"<<endl;
        }
    }

    return 0;
}