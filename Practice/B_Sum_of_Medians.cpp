#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;
    cin>>t;
    while (t--)
    {
        long long n , k;
        cin>>n>>k;
        vector<long long>a(n*k);
        for (long long i = 0; i < (n*k); i++)
        {
            cin>>a[i];
        }
        long long i = n*k;
        long long sum=0;
        while (k--)
        {
            i -= (n/2)+1;
            sum +=a[i];
        }
        cout<<sum<<endl;
        
        
    }
    
    return 0;
}