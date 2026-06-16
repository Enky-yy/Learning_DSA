#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int BestTime(vector <int> a , int n){
    int i=n-1,j=0;
    int max_profit = INT_MIN;
    int diff=0;
    while (j<=i)
    {
        diff = a[i];
        if(j<=i){
            max_profit = max(max_profit, diff-a[j]);
            j++;
        }
        i--;
    }
    return max_profit;    
    
}

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    cout << BestTime(prices, prices.size()) << endl;

    return 0;
}
