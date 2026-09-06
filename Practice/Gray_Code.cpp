#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int n ;
    cin>>n;
    unordered_set<string>s;
    string ss ;
    ss+= string(n, '0');
    s.insert(ss);
    cout<<ss<<endl;
    for (int i = n-1; i ==0; i--)
    {
        ss[i]='1';
        s.insert(ss);
        cout<<ss<<endl;
    }
    
    return 0;
}