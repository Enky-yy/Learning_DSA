#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int findKthPositive(vector<int> &arr, int k){
    int low = 0 ;
    int high = arr.size()-1;

    while (low<high)
    {
        int mid = low + (high -low)/2;

        int removed = arr[mid]-(mid+1);

        if(removed <k){
            low = mid+1 ;
        }
        else{
            high = mid-1;
        }
    }
    return k+high+1;
}

int main() {
    vector<int> vec = {1,2,3,4};  
    int k =2;

    int ans = findKthPositive(vec, k);  // Call method

    cout << "The missing number is: " << ans << "\n";  // Print result
    return 0;
}