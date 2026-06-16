#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int checkInArrays(vector<int> &arr1, vector<int> &arr2, int mid)
{
    int n1 = arr1.size() ;
    int n2 = arr2.size();
    int cnts = 0;
    int i =0;
    int j=0;

    while (i<n1 && j<n2)
    
    {
        if(arr1[i]<=mid){
            cnts++;
            i++;
        }
        else if (arr2[j]<=mid)
        {
            cnts++;
            j++;
        }
        else break;
    }
    return cnts;
}

int KthElement(vector<int> &arr1, vector<int> &arr2, int k)
{
    int low = min(arr1.front(), arr2.front());
    int high = max(arr1.back(), arr2.back());

    while (low <=high)
    {
        int mid = low + (high - low) / 2;

        int counts = checkInArrays(arr1, arr2 , mid);

        if(counts<k){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return low;
}

int main()
{
    vector<int> a = {2, 3, 6, 7, 9};
    vector<int> b = {1, 4, 8, 10};
    int k = 5;
    
    cout << "The " << k << "-th element of two sorted arrays is: "
         <<KthElement(a, b, k) << '\n';
    return 0;
}