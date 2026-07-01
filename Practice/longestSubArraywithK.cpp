#include <bits/stdc++.h>

using namespace std;

int subArrayK(vector<int> &a, int k, int n)
{
    int left = 0;
    int right = 0;
    int sum = a[0];
    int maxlen = 0;
    while (right < n)
    {
        while (left <= right && sum > k)
        {
            sum -= a[left];
            left++;
        }

        if (sum == k)
            maxlen = max(maxlen, right - left + 1);

        right++;
        if (right < n)
        {
            sum += a[right];
        }
    }
    return maxlen;
}

int main()
{
    vector<int> nums = {10, 5, 2, 7, 1, 9};
    int k = 15;

    int ans = subArrayK(nums, k, 6);

    cout << "The length of longest subarray having sum k is: " << ans;
    return 0;
}