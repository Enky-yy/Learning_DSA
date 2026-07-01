#include <bits/stdc++.h>

using namespace std;
int MaxSubArraySum(vector<int> &a , int n){
    int maxi = INT_MIN;
    int sum=0;
    for (int i = 0; i < n; i++)
    {
        sum +=a[i];
        maxi = max(sum , maxi);
        if(sum<0){
            sum=0;
        }
    }
    return maxi;
    
}

int main() {
    vector<int> arr = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };

   

    int maxSum = MaxSubArraySum(arr, arr.size());

    cout << "The maximum subarray sum is: " << maxSum << endl;

    return 0;
}