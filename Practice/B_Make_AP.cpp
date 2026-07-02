#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n = 3;
        vector<long long> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        long long na = (2*a[1]) - a[2];
        long long nb = (a[2]+a[0])/2;
        long long nc = (2*a[1]) - a[0];

        bool check = false;

        if((na/a[0]) >0 && (na%a[0])==0 )
            check=true;
        if((nb/a[1]) >0 && (nb%a[1])==0 && (a[2] - a[0]) % 2 == 0)
            check=true;
        if((nc/a[2]) >0 && (nc%a[2])==0 )
            check=true;
        

        if (check)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}