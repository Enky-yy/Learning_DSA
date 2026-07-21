#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class DisjointSet {
    vector<int> rank, parent, size;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]); // Path compression
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        } else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        } else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};


int main() {
    int n , m;
    cin>>n>>m;
    DisjointSet ds(n);
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
        if(ds.findUPar(i)!=ds.findUPar(i+1)){
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