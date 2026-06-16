#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int minRotated(vector<int> & arr, int n ){
    int low = 0; 
    int high = n-1;

    while (low<high)
    {
        int mid = low + (high - low)/2;

        if(arr[mid]>arr[high]){
            low = mid+1;
        }
        else
        {
            high = mid;
        }
        
    }
    return arr[low];
}

int main() {
    vector<int> arr;
    arr={324565, 53564576,1,2,2,2,2,3,7,455};
    cout<< minRotated(arr,arr.size())<< endl;
    return 0;
}