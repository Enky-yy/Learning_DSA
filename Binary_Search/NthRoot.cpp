#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int NthRoot(int x , int n){
    int low = 1, high = n;

    if (x==0) return 1;
    
    while (low<=high)
    {
        int mid = low + (high-low)/2;

        long long ans = 1;

        for (int i = 0; i < x; i++)
        {
            ans *=mid;
            if (ans > n) break;
        }
        
        if (ans == n) return mid;

        if (ans < n) low = mid+1;

        else high = mid-1;
    }
    return -1;
}

int main() {
    cout<< NthRoot(3,65)<<endl;
    return 0;
}