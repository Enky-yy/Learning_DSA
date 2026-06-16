#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int twosum(vector<int> a, int k){
    int left =0, right =0;
    int n = a.size();
    int sum = 0;
    while (right<n)
    {
        
        if (left<right){
            sum = a[right];
            sum += a[left];
        }
        if(sum ==k){
            return true;
        }
        else{
            left++;
        }
        right++;
    }
    return false;
    
}

int main() {
    
    return 0;
}