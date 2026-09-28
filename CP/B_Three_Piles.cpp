#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int t;
    cin>>t;
    while (t--)
    {
        ll a , b,c;
        cin>>a>>b>>c;
        ll curr = abs(a-b);
        ll after = abs(a+c-b);
        cout<<max(curr, after)<<endl;
    }
    
    return 0;
}