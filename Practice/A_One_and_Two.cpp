#include <bits/stdc++.h>

using namespace std;

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        vector<long long> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        long long total_number_of_twos = 0; 
        long long current_number_of_twos = 0; 
       
        for (long long i = 0; i < n; i++) 
        {
            if (arr[i] == 2) 
                total_number_of_twos++; 
        } 

        long long ans = -1; 

        
        for (long long i = 0; i < n; i++) 
        {
            if (arr[i] == 2) 
                current_number_of_twos++; 

            
            if ((current_number_of_twos) == (total_number_of_twos - current_number_of_twos))
            {
                ans = i + 1; 
                break; 
            }
        }

        cout << ans << endl;
    }

    return 0;
}