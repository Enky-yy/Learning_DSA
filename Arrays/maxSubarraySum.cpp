#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int maximumsubarraysum(vector<int> a, int n){
    int sum = INT_MIN;
    int temp_sum=0;
    for (int i = 0; i < n; i++)
    {
        temp_sum +=a[i];
        if (temp_sum>sum){
            sum = temp_sum;
        }
        if(temp_sum<0){
            temp_sum=0;
        }
    }
    
}

int main() {
    
    return 0;
}