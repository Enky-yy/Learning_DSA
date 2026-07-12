#include <bits/stdc++.h>

using namespace std;

bool check(long long n){
    long long num = n;
    while (num!=0)
    {
        long long x = num%10;
        if(x!=0 && n%x !=0)
            return false;
        num = num/10;

    }
    return true;
    
}

int main() {
    int t;
    cin>>t;
    while (t--)
    {
        long long s;
        cin>>s;
        
        while (!check(s))
        {
            s+=1;
        }
        cout<<s<<endl;
        
        
    }
    
    return 0;
}