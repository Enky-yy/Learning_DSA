#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin>>t;
    while (t--)
    {
        long long n, x;
        cin>>n>>x;
        vector<long long> a(n);
        long long sum = 0;
        long long sum2=0;
        for (long long i = 0; i < n; i++)
        {
            cin>>a[i];
        }
        for (long long i = 0; i < n; i++)
        {
            sum +=a[i];
            sum2 += ceil(a[i] * 1.0 /x);
        }
        sum = ceil(sum*1.0/x);
        
        cout<<sum<<" "<<sum2<<endl;

        
    }
    
    return 0;
}