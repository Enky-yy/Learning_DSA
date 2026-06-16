#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> merge(vector<int> &arr, int low, int mid, int high){
    int i =low, j=mid+1;
    vector<int> ans;
    while (i<=mid && j<=high)
    {
        if(arr[i]<=arr[j]){
            ans.push_back(arr[i]);
            i++;
        }
        else{
            ans.push_back(arr[j]);
            j++;
        }
    }
    while (i<=mid)
    {
        ans.push_back(arr[i]);
        i++;
    }
    while (j<=high)
    {
        ans.push_back(arr[j]);
        j++;
    }
    for (int i = low; i <=high; i++)
    {
        arr[i] = ans[i-low];
    }
    
    
    return ans;
}

void SortingAlgo(vector<int> &arr, int low, int high){
    if(low==high) return;
    int mid = low+ ((high-low)/2);
    SortingAlgo(arr, low, mid);
    SortingAlgo(arr, mid+1, high);
    merge(arr, low,mid,high);
}

int main() {
    vector<int> arr;
    arr={2,6,4,8,1,3};
    int n = arr.size();
    SortingAlgo(arr,0,n-1);
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}