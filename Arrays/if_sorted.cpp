#include<iostream>
#include <bits/stdc++.h>

using namespace std;

int ifSorted(vector<int> a , int n){
    for (int i = 1; i < n; i++)
    {
        if (a[i]>=a[i-1]){
        }
        else{
            return false;
        }
        return true;
    }
    
}