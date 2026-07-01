#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin>>t;
    while (t--)
    {
        long long n;
        cin>>n;
        vector<long long > arr(n);
        for (int i = 0; i < n; i++)
        {
            cin>>arr[i];
        }
        int check =0;

        for (int i = 0; i < n; i++)
        {
            for (int j = i+1; j < n; j++)
            {
                if(__gcd(arr[i], arr[j])<=2)
                    check=1;
            }
            
        }
        if(check){
            cout<<"Yes"<<endl;
        }
        else
            cout<<"No"<<endl;
        
        
    }
    
    return 0;
}