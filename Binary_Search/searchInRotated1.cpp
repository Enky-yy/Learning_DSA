#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int searchRotated(vector<int> &arr, int n, int x){
    int low = 0, high = n-1;
    int ans=-1;
    while (low<=high)
    {
        int mid = low + (high-low)/2;

        if (arr[mid ]== x){
            ans = mid;
        }
        if(arr[low]<= arr[mid]){
            if (arr[low]<=x && x<= arr[mid]){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        else{
            if(arr[mid]<= x && arr[high]>=x){
                low = mid+1;
            }
            else high = mid-1;
        }
    }
    return ans;
}

int main() {
    vector<int> arr;
    arr={324565, 53564576,1,2,2,2,2,3,7,455};
    cout<< searchRotated(arr,arr.size(),2)<< endl;
    return 0;
}