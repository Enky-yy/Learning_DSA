#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long a, b;
        cin >> a >> b;
        long long ops = -1;

        long long ra = a;
        long long rb = b;

        while (ra % 2 == 0)
        {
            ra /= 2;
        }
        while (rb % 2 == 0)
        {
            rb /= 2;
        }

        if (ra != rb)
            cout << -1 << endl;
        else
        {
            a/=ra;
            b/=rb;

            a = log2(a);
            b = log2(b);

            ops = ceil(abs(a-b)/3.0);
            cout<<ops<<endl;
        }

    }

    return 0;
}