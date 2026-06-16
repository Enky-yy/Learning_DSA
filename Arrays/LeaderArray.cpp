#include <iostream>
#include <bits/stdc++.h>

using namespace std;
vector<int> leaders(vector<int>& nums) {
        vector<int> ans;
        
        if(nums.empty()) {
            return ans;
        }
        
        int max = nums[nums.size() - 1];
        ans.push_back(nums[nums.size() - 1]);
        
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] > max) {
                ans.push_back(nums[i]);
                max = nums[i];
            }
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }

int main() {
    vector<int> nums = {10, 22, 12, 3, 0, 6};
    
    // Get leaders using class method
    vector<int> ans = leaders(nums);
    int t = ans.size();
    
    cout << "Leaders in the array are: ";
    for (int i = 0; i < t; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    
    return 0;
}