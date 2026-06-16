#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int lowerBound(vector<int>&arr , int n , int k){
    int low = 0 , high =n-1;
    int ans=n;

    while (low<=high)
    {
        int mid = low + (high -low)/2;

        if(arr[mid]>=k){
            high = mid -1;
            ans = mid;
        }
        else{
            low = mid+1;
        }
    }
    return ans;
}

int maxNumberOfOnes(vector<vector<int>> &arrb , int n, int m){
    int cnt_max = 0;
    int index = -1;

    for (int i = 0; i < n; i++)
    {
        int cnt_ones = m - lowerBound(arrb[i], m,1 );
        if (cnt_ones>cnt_max){
            cnt_max = cnt_ones;
            index =i;
        }
    }
    return index+1;
}

int main() {
    vector<vector<int>> matrix = {{1, 1, 1}, {0, 0, 1}, {0, 0, 0}};
    int n = 3, m = 3;

    cout << "The row with maximum no. of 1's is: " << maxNumberOfOnes(matrix, n, m) << '\n';
    return 0;
}