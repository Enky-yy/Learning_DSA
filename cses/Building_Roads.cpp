#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class DisjointSets
{
    vector<int> size, rank, parent;

public:
    DisjointSets(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int findPar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findPar(parent[node]);
    }

    void unionBySize(int u, int v)
    {
        int ulp_u = findPar(u);
        int ulp_v = findPar(v);

        if (ulp_u == ulp_v)
            return;
        else if (ulp_u > ulp_v)
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
        else
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
    }
};

int main() {
    int n , m;
    cin>>n>>m;
    DisjointSets ds(n);
    for (int i = 0; i < m; i++)
    {
        int start , end;
        cin>>start;
        cin>>end;
        ds.unionBySize(start, end);
    }
    vector<pair<int, int>>ans;
 
    for (int i = 1; i < n; i++)
    {
        if(ds.findPar(i)!=ds.findPar(i+1)){
            ds.unionBySize(i,i+1);
            ans.push_back({i,i+1});
        }
    }
 
    if(ans.size()==0)
        cout<<0<<endl;
    else{
        cout<<ans.size()<<endl;
        for(auto it : ans){
            cout<<it.first<<" "<<it.second<<endl;
        }
    }
    
    
    return 0;
}