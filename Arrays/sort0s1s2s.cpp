#include <iostream>
#include <bits/stdc++.h>

using namespace std;
vector<int> sort1s2s0s(vector<int>a , int n){
    int mid = 0;
    int high = n-1;
    int low = 0;
    while (mid <= high)
    {
        if (a[mid]==0){
            swap(a[mid], a[low]);
            low++;
        }
        else if(a[mid]== 2){
            swap(a[mid], a[high]);
            high--;
            continue;
        }
        mid++;
    }
    return a;
    
}

int main() {

    return 0;
}