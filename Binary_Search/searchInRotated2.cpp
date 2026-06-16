#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int searchRotated(vector< int > & arr , int n , int x){
    int low = 0, high =n-1;
    
    while (low<=high)
    {
        int mid = low + (high -low)/2;

        if (arr[mid]== x){
            return true;
        }
        
        if (arr[low] == arr[mid] && arr[mid]== arr[high]){
            low ++ ;
            high --;
            continue;
        }

        if (arr[low]<= arr[mid]){
            if(arr[mid]>=x  && arr[low]<=x){
                high = mid- 1;
            }
            else{
                low = mid+1;
            }
        }
        else{
            if(arr[mid]<=x  && arr[high]>=x){
                low = mid+ 1;
            }
            else{
                high = mid-1;
            }
        }
    }
    return false;
}

int main() {
    vector<int> arr;
    arr={324565, 53564576,1,2,2,2,2,3,7,455};
    cout<< searchRotated(arr,arr.size(),77)<< endl;
    return 0;
}