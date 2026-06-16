#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int checkAnswer(vector<int> &arr , int mid){

    int ans =0;

    for (int num : arr)
    {
        if(num%2 == 0){
            ans +=(num/mid);
        }
        else{
            ans +=(num/mid);
            ans++;
        }
    }
    return ans;
}

int smallestDivisor(vector<int> &arr, int k){
    int low = 1;
    int high = *max_element(arr.begin(), arr.end());

    while (low<=high)
    {
        int mid = low + (high - low)/2;

        if(checkAnswer(arr, mid)>k){
            low = mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return low;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int limit = 8;
    int ans = smallestDivisor(arr, limit);
    cout << "The minimum divisor is: " << ans << "\n";
    return 0;
}