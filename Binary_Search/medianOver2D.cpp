#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int countLessEqual(vector<int> &row, int mid)
{
    return upper_bound(row.begin(), row.end(), mid) - row.begin();
}

int median2DMatrix(vector<vector<int>> &arr)
{
    int n = arr.size();
    int m = arr[0].size();

    int low = arr[0][0];

    int high = arr[0][m - 1];
    for (int i = 1; i < n; i++)
    {
        low = min(low, arr[i][0]);
        high = max(high, arr[i][m - 1]);
    }
    cout << high << " " << low << endl;
    sort(arr.begin(), arr.end());

    while (low < high)
    {
        int mid = (low + high) / 2;

    
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            count += countLessEqual(arr[i], mid);
        }

        // If count is less than half, median is greater
        if (count < (m * n + 1) / 2)
            low = mid + 1;
        else
            high = mid;
    }

    // Final low is the median
    return low;
}

int main()
{
    vector<vector<int>> matrix = {
        {1, 3, 5},
        {2, 6, 9},
        {3, 6, 9}};
    cout << "Median: " << median2DMatrix(matrix) << endl;
    return 0;
}