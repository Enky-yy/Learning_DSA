#include <bits/stdc++.h>

using namespace std;

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        long long a, b;
        cin >> a >> b;
        long long maxi = INT_MAX;
        for (long long i = 0; i < 32; i++)
        {
            long long operations=i;
            long long divisor = b+i;
            if(divisor==1)
                continue;
            long long a1=a;
            while (a1>0)
            {
                a1=a1/divisor;
                operations++;
            }
            maxi = min(operations, maxi);
             
        }
        
        cout << maxi << endl;
    }
    

    return 0;
}