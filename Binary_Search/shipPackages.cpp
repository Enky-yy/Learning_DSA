#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int daysNeeded(vector<int> &arr , int capacity){
    int day =1;
    int currentLoad = 0;

    for (int w:arr){
         if(currentLoad + w > capacity){
            day ++;
            currentLoad = w;
         }
         else{
            currentLoad +=w;
         }
    }
    return day;
}

int capacitySize(vector<int> &arr , int limit){
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(),0);

    while (low<high)
    {
        int mid = low + (high - low)/2;

        if(daysNeeded(arr, mid) > limit){
            low = mid+1;
        }
        else{
            high = mid;
        }
    }
    return low;
}

int main() {
    vector<int> weights = {1, 2, 3, 4, 5};

    int d = 2;

    cout << capacitySize(weights, d) << "\n";
    return 0;
}