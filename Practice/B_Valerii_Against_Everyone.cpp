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
        };
        unordered_set<long long>s(n);
        for (long long i = 0; i < n; i++)
        {
            s.insert(a[i]);
        }

        if(s.size()<n)
            cout<<"YES"<<endl;
        else    
            cout<<"NO"<<endl;
        
        
        
        
    }
    
    return 0;
}