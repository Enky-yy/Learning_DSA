#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;
    cin>>t;
    while (t--)
    {
        long long x, n;
        cin>>x>>n;
        long long final_posi = 0;
        
        if(n%4==1){
            final_posi = -n;
        }
        else if(n%4==2)
            final_posi=1;
        else if (n%4==3)
        {
            final_posi =n+1; 
        }
        else if(n%4==0){
            final_posi=0;
        }

        if(x%2==0)
            cout<<x+final_posi<<endl;
        else
            cout<<x-final_posi<<endl;
    }
    
    return 0;
}