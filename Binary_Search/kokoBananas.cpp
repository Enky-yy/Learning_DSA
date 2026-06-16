#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int calculateHours(vector<int> &arr, int speed){
    int totalH=0;
    for (int bananas:arr)
    {
        totalH+= ceil((double)bananas/speed);
    }
    return totalH;
}

int Bananas(vector<int> &arr , int h ){
    int low =1 , high = *max_element(arr.begin(), arr.end());
    int ans = high;

    while (low<high)
    {
        int mid = low + (high-low)/2;

        if(calculateHours(arr ,mid)<=h){
            ans = mid;
            high = mid-1;
        }
        else low=mid+1;
    }
    return ans;
}

int main() {
    vector<int> piles = {3, 6, 7, 11};
    int h = 8;

    cout<<Bananas(piles,h)<<endl;
    return 0;
}