#include <bits/stdc++.h>

using namespace std;

int main() {
    long long t;
    cin>>t;
    while (t--)
    {
        long long w,h;
        cin>>w>>h;
        long long max_area_x=0;
        long long max_area_b=0;
        for (long long i = 0; i < 2; i++)
        {
            long long n;
            cin>>n;
            vector<long long>a(n);
            for (long long i = 0; i < n; i++)
            {
                cin>>a[i];

            }
            max_area_x= max(max_area_x , h*(a[n-1]-a[0]));
            
        }
        for (long long i = 0; i < 2; i++)
        {
            long long n;
            cin>>n;
            vector<long long>a(n);
            for (long long i = 0; i < n; i++)
            {
                cin>>a[i];

            }
            max_area_x= max(max_area_x , w*(a[n-1]-a[0]));
            
        }
        cout<<max(max_area_b,max_area_x)<<endl;
        
    }
    
    return 0;
}