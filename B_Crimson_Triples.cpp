#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin>>t;
    while (t--)
    {
        long long n;
        cin>>n;
        long long ans=0;

        for (long long i = 1; i <=n;)
        {
            long long divisor = n/i;
            long long remainder = n/divisor;
            ans += 1LL*(remainder-i+1)*divisor*divisor;

            i = remainder+1;
        }
        cout<<ans<<endl;
        
    }
    
    return 0;
}