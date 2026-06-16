#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    // Sort intervals based on starting time
    sort(intervals.begin(), intervals.end());

    // Vector to store final merged intervals
    vector<vector<int>> merged;

    // Traverse each interval
    for (auto interval : intervals)
    {
        // If merged is empty or current interval does not overlap
        if (merged.empty() || merged.back()[1] < interval[0])
        {
            // Add current interval as a new non-overlapping block
            merged.push_back(interval);
        }
        else
        {
            // Overlapping: merge by extending the end time
            merged.back()[1] = max(
                merged.back()[1],
                interval[1]);
        }
    }

    return merged;
}

int main()
{

    return 0;
}