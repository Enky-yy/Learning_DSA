#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int n;
    cin>>n;
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    long long total=0;
    for (ll i = 1; i < n; i++)
    {
        ll diff = arr[i] - arr[i-1];

        if(diff>0)
            diff=0;
        arr[i]= arr[i]-diff;
        total += diff;
    }
    cout<<-total<<endl;
    
    return 0;
}