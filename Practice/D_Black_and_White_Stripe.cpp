#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin>>t;
    while (t--)
    {
        long long n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        vector<long long> prefixSum(n+1, 0);
        for (int i = 0; i <n; i++)
        {
            prefixSum[i+1] = prefixSum[i] + (s[i]=='W');
        }
        long long mini = INT_MAX;

        for (int i = 0; i <=n-k; i++)
        {
            mini = min(mini , prefixSum[i+k]- prefixSum[i]);
        }
        cout<<mini<<endl;
        
        
        
    }
    
    return 0;
}