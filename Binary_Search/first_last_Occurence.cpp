#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int Last(vector<int> &arr , int n , int x){
    int low = 0, high = n-1;
    int last = -1;
    while (low<=high)
    {
        int mid= low + (high-low)/2;

        if(arr[mid]==x){
            last = mid;
            low= mid+1;
        }
        else if(arr[mid]<x){
            low = mid +1;
        }
        else{
            high = mid-1;
        }
    }
    return last;
}

int First(vector<int> &arr , int n , int x){
    int low = 0, high = n-1;
    int first = -1;
    while (low<=high)
    {
        int mid= low + (high-low)/2;

        if(arr[mid]==x){
            first = mid;
            high = mid-1;
        }
        else if(arr[mid]>x){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return first;
}

int main() {
    vector<int> arr;
    arr={1,2,3,5,5,5,5,7,7,455,33445};
    int last = Last(arr, arr.size(),5);
    int first = First(arr, arr.size(),5);
    cout<<last<<" "<< first<<endl;
    cout<<"Number of occurence ="<< last-first+1<<endl;
    return 0;
}