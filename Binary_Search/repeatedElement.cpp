#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int searchRepeated(vector<int> &arr , int n){
    int low =1, high =n-2;

    if(n==1) return arr[n-1];

    while (low<=high)
    {
        int mid = low + (high -low)/2;

        if(arr[mid]!= arr[mid+1] && arr[mid]!= arr[mid-1]) return arr[mid];

        if(mid%2==0 && arr[mid]==arr[mid+1]) low = mid+1;

        else if (mid%2!=0 && arr[mid]==arr[mid-1]) low = mid+1;

        else high = mid-1;
    }
    return -1;
}

int main() {
    vector<int> arr;
    arr={1,1,2,2,3,3,7,455,455};
    cout<< searchRepeated(arr,arr.size())<< endl;
    return 0;
}