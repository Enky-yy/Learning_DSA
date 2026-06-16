#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int correctOrder(vector<int> &arr , int mid){
    int n = arr.size();

    int students =1;

    long long pagesStudent= 0;

    for (int i = 0; i < n; i++)
    {
        if(pagesStudent + arr[i] <= mid){
            pagesStudent +=arr[i];
        }
        else{
            students++;
            pagesStudent= arr[i];
        }
    }
    return students;
}

int maximumPages(vector<int> &arr , int m){

    int n = arr.size();
    if(m > n) return -1;
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);

    while (low<=high)
    {
        int mid = low + (high-low)/2;

        int students = correctOrder(arr,mid);

        if(students > m){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return low;
}

int main() {
    vector<int> arr = {25, 46, 28, 49, 24};
    int m = 4;
    int ans = maximumPages(arr,m);
    cout << "The answer is: " << ans << "\n";
    return 0;
}