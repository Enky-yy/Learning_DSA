#include <bits/stdc++.h>

using namespace std;

int main() {
    long long t;
    cin>>t;
    while (t--)
    {
        long long n;
        cin>>n;
        vector<long long> a(n);
        for (long long i = 0; i < n; i++)
        {
            cin>>a[i];
        }
        if(n==1)
            cout<<a[0]<<endl;
        else{
            sort(a.rbegin(), a.rend());
            for (long long i = 0; i < n; i++)
            {
                cout<<a[i]<<" ";
            }
            cout<<endl;
            
        }
        
    }
    
    return 0;
}