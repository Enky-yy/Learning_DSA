#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin>>t;
    while (t--)
    {
        int n ;
        cin>>n;

        long long ans =0;

        for (int i = 1; i <=n; )
        {
            int divisor = n/i;
            int remainder = n/divisor;
            ans += 1LL * (remainder-i+1)*divisor*divisor;

            i =remainder+1;
        }
        cout<<ans<<endl;
        
    }
    
    return 0;
}