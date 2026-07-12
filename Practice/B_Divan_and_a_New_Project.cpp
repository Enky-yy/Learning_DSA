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
        vector< long long> a(n);
        for (long long i = 0; i < n; i++)
        {
            cin >> a[i];
    
        }
        vector<pair<long long, long long>> building_map;
		for (int i = 0; i < n; i++)
			building_map.push_back({a[i], i});

        sort(building_map.rbegin(), building_map.rend());

        vector<long long> ans(n + 1, 0);

        ans[0] = 0;

        long long posi = 1;
        long long time = 0;

        for (long long i = 0; i<n; i++)
        {
            ans[building_map[i].second +1]=posi;

            time += 2LL*abs(posi)*building_map[i].first;

            if(posi<0)
                posi = abs(posi)+1;
            else
                posi = - posi;
        }
        cout<<time<<endl;
        for(auto it : ans)
            cout<<it<<" ";
        cout<<endl;
    }

    return 0;
}