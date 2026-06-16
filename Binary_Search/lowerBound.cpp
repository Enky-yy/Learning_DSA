#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int lowerBound(vector<int> &arr , int n , int x){
    int low = 0 , high = n-1;
    int ans = n;
    while (low<=high)
    {
        int mid = low + ((high-low)/2);

        if (arr[mid]>=x){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return ans;
    
}

int upperBound(vector<int> &arr , int n, int x){
    int low = 0 , high= n-1;
    int ans = n;
    while (low<=high)
    {
        int mid = low + (high-low)/2;
        
        if (arr[mid] <=x){
            ans = mid;
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return ans;
}

int main() {
    vector<int> arr;
    arr={1,2,3,5,7,455,33445};
    int n = arr.size();
    cout<< arr[lowerBound(arr,n,9)]<< endl;
    cout<< arr[upperBound(arr,n,9)]<< endl;
    return 0;
}