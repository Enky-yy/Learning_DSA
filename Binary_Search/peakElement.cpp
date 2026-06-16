#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int peakElement(vector<int> &arr , int n ){
    int low = 1,high = n-2;

    while (low<=high)
    {
        int mid = low + (high - low)/2;

        if (arr[mid]>arr[mid-1] && arr[mid]> arr[mid+1]) return mid;

        else if (arr[mid]>arr[mid-1])
        {
            low = mid+1;
        }
        else{
            high = mid;
        }
    }
    return -1;
}

int main() {
    vector<int> arr = {1, 2, 1, 3, 5, 6, 4};
    cout<< peakElement(arr,arr.size())<< endl;
    return 0;
}