#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pll = pair<int,int>;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n + 1);
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        arr[a].push_back(b);
    }
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({n+1, 1});
    vector<int> visits(n + 1, n+1);
    vector<int> parent(n + 1, -1);
    visits[1] = n+1;
    while (!pq.empty())
    {
        auto [steps, node] = pq.top();
        pq.pop();
        if(visits[node]<  steps)
            continue;
        if(visits[n]!=n+1)
            break;

        for (auto it : arr[node])
        {
            if (visits[it] > (steps -1))
            {
                parent[it] = node;
                visits[it] = steps - 1;
                pq.push({steps -1 , it});
            }
        }
    }

    if (visits[n] == n+1)
        cout << "IMPOSSIBLE" << endl;
    else
    {
        
        int i = n;
        vector<int> ans;
        ans.push_back(i);
        while (parent[i]!=-1)
        {
            i = parent[i];
            ans.push_back(i);
            
        }
        reverse(ans.begin(), ans.end());
        cout <<ans.size()<< endl;
        for(auto it : ans)
            cout<<it<<" ";
        cout<<endl;
        

    }

    return 0;
}