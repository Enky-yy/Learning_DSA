#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int t;
    cin>>t;
    while (t--)
    {
        int n ;
        cin>>n;
         
        vector<int> parents(n+1);

        for (int i = 2; i <= n; i++)
        {
            cin>>parents[i];
        }

        int m;
        cin>>m;

        vector<int>dams(n+1);

        for (int i = 0; i < m; i++)
        {
            int x;
            cin>>x;
            dams[x]=1;
        }


        vector<int>ans;

        for (int i = n; i >=2; i--)
        {
            if(!dams[i])
                continue;

            int node = parents[i];

            if(dams[node])
                ans.push_back(i);

            else
                dams[node]=1;

        }

        cout<<ans.size();

        for(auto it : ans)
            cout<<' '<<it;

        cout<<endl;
        
        
        
    }
    
    return 0;
}