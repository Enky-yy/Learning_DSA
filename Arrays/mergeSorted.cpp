#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void mergeSorted(vector<int> &a,int m,vector<int> &b,int n){
    int i=0, j=0;
    while (i<(m+n))
    {
        if(a[i]>b[j]){
            swap(a[i],b[j]);
        }
        else if (a[i]< b[j])
        {
            i++;
        }
        else j++;
        
        
    }
    
}

int main() {
    
    return 0;
}