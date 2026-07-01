#include <bits/stdc++.h>

using namespace std;

const long long mod = 998244353;

long long matrixPow(long long number , long long power)
{   long long ans =1;
    while(power){
        if(power & 1){
            ans = ans*number % mod;
        }
        number = number*number % mod;
        power>>=1;
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, m, r, c;
        cin >> n >> m >> r >> c;

        if (r * c == 1)
            cout << 1 << endl;

        else
        {
            long long free = (r-1) * m  + (c-1) *n - (r-1)*(c-1);
            cout<<matrixPow(2,free)<<endl;
        }
    }

    return 0;
}