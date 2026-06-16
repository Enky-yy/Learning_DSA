#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int Occurence(vector<int> &arr, int n){
    unordered_map<int,int> mpp;
    for (int i = 0; i < n; i++)
    {
        if(mpp.find(arr[i])!= mpp.end()){
            mpp[arr[i]];
        }
        else{
            mpp[arr[i]]++;
        }
    }
}

int main() {
    vector<int> arr;
    arr={2,6,4,8,1,3};
    int n = arr.size();
    cout<<Occurence(arr, n)<<endl;
    return 0;
}