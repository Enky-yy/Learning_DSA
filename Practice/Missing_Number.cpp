#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int n;
    cin>>n;
    ll sum=0;
    for(int i =1 ; i<n;i++){
        int x;
        cin>>x;
        sum = sum+ x-i;
    }
    sum = sum-n;
    cout<<-(sum)<<endl;
    
    return 0;
}