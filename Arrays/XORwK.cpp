#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int Counter(vector<int>&a, int k){
    map<int  , int> mpp;
    int cnt=0;
    int xr=0;
    mpp[xr]++;
    int n = a.size();

    for (int i = 0; i < n; i++)
    {
        xr = xr^a[i];
        int x= xr^k;
        cnt+= mpp[x];
        mpp[xr]++;
    }
    return cnt;
    
}

int main() {
    
    return 0;
}