#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin>>t;
    while (t--)
    {
        long long n;
        cin>>n;
        vector<long long> a(n);
        for (int i = 0; i < n; i++)
        {
            cin>>a[i];
        }
        long long k = abs(a[0]-1);
        for (int i = 1; i < n; i++)
        {
            k = gcd(k , abs(a[i]-(i+1)));
        }

        cout<<k<<endl;
        
        
    }
    
    return 0;
}