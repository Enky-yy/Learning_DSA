#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n , d;
        cin>>n>>d;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin>>arr[i];
        }

        // lets calculate prefix sum one by one

        vector < long long> prefixSum(3*n+1,0);
        for (int i = 0; i < 3*n; i++)
        {
            prefixSum[i+1]= prefixSum[i] + arr[i%n];
        }

        long long maximum=0;

        for (int i = 0; i < n; i++)
        {
            long long left = i+n-d;
            long long right = i+n+d;

            long long sadness= prefixSum[right+1]- prefixSum[left]-arr[i];
            long long happiness= 2LL*d*arr[i] - sadness;
            if(happiness>=0) maximum +=happiness;
        }

        cout<<maximum<<endl;
        
        
        
    }
    return 0;
}