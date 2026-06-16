#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int partition(vector<int> &arr, int low, int high)
{
    // Choose the last element as pivot
    int pivot = arr[high];

    // Initialize i to place smaller elements
    int i = low - 1;

    // Traverse the array
    for (int j = low; j < high; j++)
    {
        // If element is smaller than or equal to pivot
        if (arr[j] <= pivot)
        {
            // Increment i and swap with j
            i++;
            swap(arr[i], arr[j]);
        }
    }

    // Place pivot in correct position
    swap(arr[i + 1], arr[high]);

    // Return pivot index
    return i + 1;
}

void quickSort(vector<int> &arr, int low, int high)
{
    // Base case: if low is not less than high
    if (low < high)
    {
        // Find pivot index after partitioning
        int pivotIndex = partition(arr, low, high);

        // Recursively sort elements before pivot
        quickSort(arr, low, pivotIndex - 1);

        // Recursively sort elements after pivot
        quickSort(arr, pivotIndex + 1, high);
    }
}

// Function to partition the array


int main()
{
    vector<int> arr;
    arr={2,6,4,8,1,3};
    int n = arr.size();
    quickSort(arr, 0 , n-1);
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}