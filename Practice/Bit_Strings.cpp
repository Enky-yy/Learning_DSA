#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll modulo = 1e9 +7;

int main() {
    int n;
    cin>>n;

    ll ans=1;
    for(int i =1 ; i<=n ;i++){
        ans *=2;
        ans %=modulo;
    }
    cout<<ans<<endl;
    return 0;
}