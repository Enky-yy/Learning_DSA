#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool canWePlace(vector<int> &arr, int mid, int k){
    int count =1;
    int lastPos = arr[0];


    for (int i = 1; i < arr.size(); i++)
    {
        if(arr[i] - lastPos >=mid){
            count ++;
            lastPos = arr[i];
        }
        if(count>=k){
            return true;
        }
    }
    return false;
    
}

int MaxiMin(vector<int> &arr, int k)
{

    sort(arr.begin(), arr.end());
    int low = 1;
    int high = arr[arr.size() - 1] - arr[0];
    int ans = 0;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (canWePlace(arr, mid, k) == true)
        {
            ans = mid;
            low = mid + 1;
        }
        else{
            high = mid-1;
        }
    }
    return ans;
}

int main()
{
    vector<int> stalls = {1, 2, 8, 4, 9};
    // Number of cows
    int cows = 3;
    cout << MaxiMin(stalls, cows) << endl;
    return 0;
}