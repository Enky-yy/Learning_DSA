#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, k;
        cin >> n >> k;
        vector<long long> first(n);
        vector<long long> second(n);
        for (int i = 0; i < n; i++)
        {
            cin >> first[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> second[i];
        }
        long long maxi=INT_MIN;
        long long sum=0;
        long long ans =0;
        for (int i = 0; i < min(n,k); i++)
        {
            sum+=first[i];
            maxi = max ( maxi,second[i]);
            ans= max(ans , sum + maxi*(k-1-i));
        }
        

        cout<< ans<<endl;;
    }

    return 0;
}