#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin>>t;
    while (t--)
    {
        long long n;
        cin>>n;
        if(n<=10)
            cout<<n<<endl;
        else{
            long long ans=9;
            long long maxi =9;
            for (int i = 10; i <= n; i*=10)
            {
                if(n/i>=1)
                    ans += min((n/i), maxi);
                else{
                    break;
                }
            }
            cout<<ans<<endl;
        }
    }
    
    return 0;
}