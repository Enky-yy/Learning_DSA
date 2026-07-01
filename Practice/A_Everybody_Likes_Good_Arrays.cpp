#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin>>t;
    while (t--)
    {
        long long n;
        cin>>n;
        vector<long long> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin>>arr[i];
        }
        long long number_of_operations =0;
        for (int i = 1; i < n; i++)
        {
            if(arr[i-1]%2==0 && arr[i]%2!=0)
                continue;
            else if(arr[i]%2==0 && arr[i-1]%2!=0)
                continue;
            number_of_operations++;
        }
        cout<<number_of_operations<<endl;
        
        
    }
    
    return 0;
}