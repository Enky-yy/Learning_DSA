#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int noOfGasStationRequired(vector<int> &arr, long double mid)
{
    int n = arr.size();
    int cnts = 0;

    for (int i = 1; i < n; i++)
    {
        int noInBetween = (arr[i] - arr[i - 1]) / mid;

        if ((arr[i] - arr[i - 1]) == (mid * noInBetween))
        {
            noInBetween--;
        }
        cnts += noInBetween;
    }
    return cnts;
}

long double findDistance(vector<int> &arr, int k)
{
    long double low = 1;
    long double high = arr.back() - arr.front();

    while (low < high)
    {
        long double mid = low + (high - low) / 2;

        int gasStation = noOfGasStationRequired(arr, mid);

        if (gasStation > k)
        {
            low = mid;
        }
        else
        {
            high = mid;
        }
    }
    return high;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 4;

    long double ans = findDistance(arr, k);

    cout << "The answer is: " << ans << "\n";
    return 0;
}