#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int bs(vector<int>&arr , int low , int high , int target){
    if(low>high) return -1;
    int mid = low +((high-low)/2);
    if (arr[mid]==target) return mid;
    else if (target>arr[mid])
    {
        return bs(arr , mid+1 , high, target);
    }
    else{
        return bs(arr, low, mid-1, target);
    }
}

int search (vector<int> arr , int target){
    return bs(arr, 0,arr.size()-1, target);
}

int main() {
    vector<int> arr;
    arr={1,2,3,5,7,455,33445};
    cout<< search(arr,9)<< endl;
    return 0;
}