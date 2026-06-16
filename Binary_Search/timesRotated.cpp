#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int timesRotated(vector<int> &arr, int n){
    int low = 0, high =n-1;

    while (low<high)
    {
        int mid = low + (high -low)/2;

        if (arr[mid]<arr[low]){
            high = mid-1;
        }
        else low = mid;
    }
    return high+1;
}

int main() {
    vector<int> arr;
    arr={324565, 53564576,1,2,2,2,2,3,7,455};
    cout<< timesRotated(arr,arr.size())<< endl;
    return 0;
}