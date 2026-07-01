#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin>>t;
    while (t--)
    {
        int n , k;
        cin>>n>>k;
        int ans=0;

        for (int i = 1; i <= n; i<<=1)
        {
            long long count = min(k , n/i);
            n-=(count*i);
            ans+=count;

            if(count<k)
                break;
        }
        cout<<ans<<endl;
        
    }
    
    return 0;
}