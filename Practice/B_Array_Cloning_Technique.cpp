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
            cin>>a[i];
        }
        
        sort(a.begin(), a.end());
        long long maxi = 1;
        long long count = 1;
        if (n == 1)
        {
            cout << 0 << endl;
            continue;
        }
        for (int i = 1; i < n ; i++)
        {
            if (a[i-1] != a[i])
            {
                count=1;
                continue;
            }
            count++;
            maxi = max(maxi , count);
        }
        // cout<<maxi<<endl;
        long long operation=0;
        while (maxi<n)
        {
            operation++;
            if(maxi*2<=n){
                operation+=maxi;
                maxi*=2;
            }
            else{
                operation +=(n-maxi);
                maxi=n;
            }
        }

        cout<<operation<<endl;
        
    }

    return 0;
}