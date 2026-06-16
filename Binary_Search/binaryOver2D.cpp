#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> binaryOver2D(vector<vector<int>> &arr, int target)
{
    int n = arr.size();
    int m = arr[0].size();

    int low = 0;
    int high = m * n - 1;
    vector<int> ans;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        int row = mid / m;
        int cols = mid % m;

        if (arr[row][cols] == target)
        {
            ans.push_back(row);
            ans.push_back(cols);
            return ans;
        }
        else if (arr[row][cols] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}};

    vector<int> arr;
    arr = binaryOver2D(matrix, 8);

    if (arr.empty())
        cout << "Not Found"<<endl;
    else{
        cout << "Found at ("<<arr[0]+1<<","<<arr[1]+1<<")"<<endl;
    }
    return 0;
}