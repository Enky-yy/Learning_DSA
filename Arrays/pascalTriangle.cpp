#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> generateRow(int row){
    long long ans=1;
    vector<int> ansRow;
    ansRow.push_back(ans);
    for (int i = 1; i < row; i++)
    {
        ans = ans * (row-i);
        ans = ans / i;
        ansRow.push_back(ans);
    }
    return ansRow;
}

vector<vector<int>> pascalTriangle(int n){
    vector<vector<int>> triangle;
    for ( int i = 1; i <=n; i++)
    {
        triangle.push_back(generateRow(i));
    }
    return triangle;
}

int main() {
    
    return 0;
}