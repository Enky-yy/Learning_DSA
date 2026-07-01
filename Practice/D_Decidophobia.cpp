#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        long long n ,d;
        cin>>n>>d;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin>>arr[i];
        }

        vector<long long > preSum(3*n+1 , 0);
        for (int i = 0; i < 3*n; i++)
        {
            preSum[i+1]= preSum[i] + arr[i%n];
        }
        long long maxi =0;
        for (int i = 0; i < n; i++)
        {
            long long l = i+n-d;
            long long r = i+n+d;
            long long coeff = preSum[r+1] - preSum[l] -arr[i];
            long long happiness = 2LL*d*arr[i] - coeff;
            if(happiness>=0)
                maxi +=happiness;
        }
        cout<<maxi<<endl;
        
        
        
    }
    return 0;
}