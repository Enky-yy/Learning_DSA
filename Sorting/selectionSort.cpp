#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void selectionSort(vector<int> &arr){
    int n = arr.size();
    for (int i = 0; i <n-2 ; i++)
    {
        int min = i;
        for (int j = i; j <= n-1; j++)
        {
            if(arr[j]<arr[min]){
                min = j;
            }
        }
        swap(arr[i], arr[min]);
        
    }
    
}

int main() {
    vector<int> arr;
    arr={2,6,4,8,1,3};
    int n = arr.size();
    selectionSort(arr);
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}