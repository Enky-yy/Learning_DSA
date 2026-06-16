#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> IntersectionTwo (vector <int> a, vector<int>b){
    int n1 = a.size();
    int n2 = b.size();
    int i=0;
    int j=0;
    vector <int> UnionArr;
    while (i<n1 && j<n2)
    {
        if(a[i]==b[j] && (a[i]!= UnionArr.back() || UnionArr.size()==0)){
            UnionArr.push_back(a[i]);
            i++;
            continue;
        }
        else if (a[i]==b[j] && (b[j]!= UnionArr.back() || UnionArr.size()==0)){
            UnionArr.push_back(b[j]);
            j++;
            continue;
        }
        else{
            if(a[i]>b[j]){
                j++;
            }
            else{
                i++;
            }
        }
    }
    return UnionArr;
}

int main() {
    
    return 0;
}