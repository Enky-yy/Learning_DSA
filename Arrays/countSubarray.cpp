#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int findAllSubarray(vector<int> &a , int k){
    map<int, int> mpp;
    mpp[0]=1;
    int prefixSum = 0, cnt=0;
    for (int i = 0; i < a.size(); i++)
    {
        prefixSum += a[i];
        int remove = prefixSum-k;
        cnt += mpp[remove];
        mpp[prefixSum]+=1;
    }
    return cnt;
}

int main() {
    
    return 0;
}