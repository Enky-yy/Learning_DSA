#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int a[] = {2,5,7,23,5};
    int largest=a[0];
    int second_largest=INT_MIN;
    int t = size(a);
    for (int i = 1; i < t ; i++)
    {
        if (a[i]>largest){
            second_largest=largest;
            largest=a[i];
        }
        else if (a[i]<largest && a[i]>second_largest){
            second_largest=a[i];
        }
    }
    cout << largest<<" "<<second_largest<<endl;
    return 0;
}