#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        int k=1 ;

        for (int i = 2; i*i <=(n); i++)
        {
            if(n%i==0){
                k=n/i;
                break;
            }
        }
        cout<<k<<" "<<n-k<<endl;
        
        
    }
    
    return 0;
}