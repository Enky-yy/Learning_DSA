#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> threeSum(vector<int> &arr, int n){
    sort(arr.begin(), arr.end());
    int sum = 0;
    vector<vector<int>> ans;
    for (int i = 0; i < n-2; i++)
    {
        if(i>0 && arr[i] == arr[i-1])continue;

        int left = i+1 , right = n-1;

        while (left<right)
        {
            sum = arr[i] + arr[left]+ arr[right];
            if(sum == 0){
                ans.push_back({arr[i] , arr[left], arr[right]});
                left++ ;
                right--;

                while (left<right && arr[left]== arr[left-1]) left++;
                while (left<right && arr[right]== arr[right+1]) right--;
                
            }
            else if (sum<0) left++;
            else right--;

        }
        
    }
    
    return ans;
}

int main()
{

    return 0;
}