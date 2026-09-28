#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int n, m;
    cin>>n>>m;
    vector<vector<int>> arr(n+1);
    for (int i = 0; i <=m; i++)
    {
        int from , to;
        cin>> from >> to;
        arr[from].push_back(to);
        arr[to].push_back(from);
    }

    vector<int> parent(n+1, -1);
    queue<int>q;
    vector<int>vis(n+1, 0);
    vis[1]=1;
    q.push(1);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (auto it : arr[node]){
            if (!vis[it]){
                vis[it]=1;
                q.push(it);
                parent[it]=node;
            }
        }

    }

    if (!vis[n]){
        cout<<"IMPOSSIBLE"<<endl;
    }
    else{
        int curr = n;
        int end =1;
        vector<int> ans;
        while (curr!=end)
        {
            ans.push_back(curr);
            curr = parent[curr];
        }
        ans.push_back(end);
        reverse(ans.begin(), ans.end());

        cout<<ans.size()<<endl;
        for(auto it : ans){
            cout<<it<<" ";
        }
        cout<<endl;
        
    }
    
    
    
    return 0;
};
