#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        map<int,int> freq;
        long long sum=0;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin>>x;
            sum+=x;
            freq[x]++;
        }
        
        long long maxCnts =0;
        int val =0;

        for(auto [x, c]: freq){
            if(c>maxCnts){
                maxCnts=c;
                val =x;
            }
        }

        int rem = n - maxCnts;

        if(maxCnts<=rem+1){
            cout<<sum<<endl;
        }
        else
            {ll ans = sum - maxCnts*1LL*val;
            cout <<ans + (rem+2)*1LL*val<<endl;}
        
    }
    
    return 0;
}