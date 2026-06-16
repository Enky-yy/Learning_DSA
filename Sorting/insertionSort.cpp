#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void insertionSort(vector<int> &arr){
    int n = arr.size();
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j >0; j--)
        {
            if(arr[j]<arr[j-1]) swap(arr[j], arr[j-1]);
        }
        
    }
    
}

int main() {
    vector<int> arr;
    arr={2,6,4,8,1,3};
    int n = arr.size();
    insertionSort(arr);
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }    
    return 0;
}