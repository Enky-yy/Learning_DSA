#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// int longestsubArray(vector<int> a , long long k){
//     map <long long, int > preSumMap;
//     long long sum = 0;
//     int maxLen=0;
//     for (int  i = 0; i < a.size(); i++)
//     {
//         sum+=a[i];
//         if(sum==k){
//             maxLen = max(maxLen, i+1);
//         }
//         int rem = sum-k;
//         if(preSumMap.find(rem)!=preSumMap.end()){
//             int len = i - preSumMap[rem];
//             maxLen = max(maxLen, len);
//         }
//         if (preSumMap.find(sum)== preSumMap.end()){
//             preSumMap[sum]=i;
//         }
//     }
//     return maxLen;
    
// }

int longestSubarray(vector<int>a , long long k){
    int i = 0, j =0;
    int maxLen =0;
    int sum = a[0];
    int n = a.size();
    while (i<n ){
        while (j<=i && sum>k)
        {
            sum -=a[j];
            j++;
        }
        if (sum ==k){
            maxLen= max(maxLen, i-j+1);
        }
        i++;
        if (i<n){
            sum = sum + a[i];
        }
    }
    return maxLen;
}

int maxLen(int A[], int n) {
  // map prefix sum -> first index seen
  unordered_map<int, int> mpp;
  // best length so far
  int maxi = 0;
  // running prefix sum
  int sum = 0;

  // iterate over the array
  for (int i = 0; i < n; i++) {
    // update running sum
    sum += A[i];

    // if sum is zero, subarray [0..i] has zero sum
    if (sum == 0) {
      // update best length
      maxi = i + 1;
    }
    // otherwise check if this sum was seen before
    else {
      // when seen, zero-sum segment between previous index + 1 and i
      if (mpp.find(sum) != mpp.end()) {
        // maximize length
        maxi = max(maxi, i - mpp[sum]);
      }
      // first time seeing this sum
      else {
        // record index
        mpp[sum] = i;
      }
    }
  }

  // return best length
  return maxi;
}

int main() {
    
    return 0;
}