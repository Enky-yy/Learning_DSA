#include <iostream>
#include <bits/stdc++.h>

// select maximum out of two and do adjacent swap

using namespace std;

void bubbleSort(vector<int> &arr){
    int n = arr.size();
    for (int i = 0; i < n-2; i++)
    {
        for (int j = 0; j < n-1-i; j++)
        {
            if(arr[j]>arr[j+1])
            swap(arr[j],arr[j+1]);
        }
        
    }
    
}

int main() {
    vector<int> arr;
    arr={2,6,4,8,1,3};
    int n = arr.size();
    bubbleSort(arr);
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}