#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool possible(vector<int> &arr , int day , int m , int k ){
    int n = arr.size();
    int cnt=0;
    int bouquets= 0;

    for (int i = 0; i < n; i++)
    {
        if(arr[i]<=day){
            cnt++;
            if(cnt==k){
                bouquets++;
                cnt=0;
            }
        }
        else{
            cnt=0;
        }
    }
    return bouquets>=m;
}

int minimumDays(vector<int> &arr , int m , int k){

    long long total = 1LL * k*m;

    if((arr.size()) < total) return -1;

    int mini = *min_element(arr.begin(), arr.end());
    int maxi = *max_element(arr.begin(), arr.end());

    int low = mini;
    int high = maxi;
    int result=-1;

    while(low<=high){
        int mid = low + (high-low)/2;

        if (possible(arr,mid,m,k)){
            result = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return result;
}

int main() {
    vector<int> arr = {7, 7, 7, 7, 13, 11, 12, 7};
    int k = 3; // number of flowers needed per bouquet
    int m = 2; // number of bouquets to make

    int ans = minimumDays(arr, k, m);

    if (ans == -1)
        cout << "We cannot make m bouquets.\n";
    else
        cout << "We can make bouquets on day " << ans << "\n";

    return 0;
}