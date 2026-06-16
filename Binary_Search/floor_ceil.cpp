#include <iostream>
#include <bits/stdc++.h>

using namespace std;



int main() {
    vector<int> arr;
    arr={1,2,3,5,7,455,33445};
    lower_bound(arr.begin(), arr.end(),9);
    cout<< arr[1]<< endl;
    
    return 0;
}