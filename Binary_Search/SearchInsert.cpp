#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int searchInsertPosition(vector<int> &arr , int n , int x){
    int low = 0, high = n-1;
    int ans = high;

    while (low<=high)
    {
        int mid = low + (high-low)/2;
        
        if (arr[mid]>=x)
        {
            high = mid-1;
            ans = mid;
        }
        else{
            low= mid+1;
        }
    }
    return ans;
}

int main() {
    vector<int> arr;
    arr={1,2,3,5,7,455,33445};
    cout<< searchInsertPosition(arr,arr.size(),2)<< endl;
    return 0;
}