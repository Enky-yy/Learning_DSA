#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int t;
    cin>>t;
    while (t--)
    {
        int n , k;
        cin>>n>>k;
        string s;
        
        cin>>s;

        // int farms = n/k;
        int cnts=0;
        for (int i = 0 ; i<n ; ){
            if (s[i]=='0'){
                cnts++;
                i = i+(k - (i%k));
            }
            else i++;
        }
        // cout<<cnts<<endl;
        cout<<(n/k) - cnts<<endl;
    }
    
    return 0;
}