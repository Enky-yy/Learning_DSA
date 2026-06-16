#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int checkSplit (vector<int> &arr , int mid){
    int n = arr.size();
    int splits =1;
    int sum = 0;

    for (int i :arr)
    {
        if(sum + i <=mid){
            sum +=i;
        }
        else{
            sum= i;
            splits++;
        }
    }
    return splits;
}

int splitArray(vector<int> &arr ,int k){
    int low = *max_element(arr.begin() , arr.end());
    int high = accumulate(arr.begin() , arr.end(), 0);

    while (low<=high)
    {
        int mid = low + (high - low)/2;

        int split = checkSplit(arr, mid);
        if(split<=k){
            high = mid -1;
        }
        else{
            low = mid +1;
        }
    }
    return low;
}

int main() {
    vector<int> arr ={3,5,1};
    int k = 3;
    cout<<splitArray(arr, k)<<endl;
    return 0;
}