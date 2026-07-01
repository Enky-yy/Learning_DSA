#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        long long maxi = a[n-1];
        long long mini = a[0];
        if(maxi == mini)
            cout<<"No"<<endl;
        else{
            cout<<"Yes"<<endl;
            cout<<maxi<<" ";
            for (int i = 0; i < n-1; i++)
            {
                cout<<a[i]<<" ";
            }
            cout<<endl;
            
        }
        
    }

    return 0;
}