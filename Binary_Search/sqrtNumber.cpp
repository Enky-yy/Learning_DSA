#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int findSqrt(int a){
    int low = 1 , high =a/2;
    int ans = 0;

    while (low<=high)
    {
        int mid = low +(high-low)/2;

        int sq = mid*mid;
        
        if(sq>a){
            high = mid-1;
            ans=mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return ans;
}

int main() {
    cout<<findSqrt(14)<<endl;
    return 0;
}

