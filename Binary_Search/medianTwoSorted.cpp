#include <iostream>
#include <bits/stdc++.h>

using namespace std;

double findMedianSortedArrays(vector <int> &a , vector<int> &b ){
    int m = a.size();
    int n = b.size();

    int low = min(a.front(), b.front());
    int high = max(a.back(), b.back());
    int ans=0;

    double mid = low + (high-low)/2;

    return mid;
}

int main() {

    
    return 0;
}