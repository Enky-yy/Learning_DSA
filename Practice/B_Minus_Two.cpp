#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int maximun(int a , int b, int c){
    if(a>=b){
        if(a>=c) return a;
        else return c;
    }
    else{
        if (b>=c) return b;
        else return c;
    }
}

int main()
{
    int t;
    cin >> t ;
    while (t--)
    {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        int odd = 0;
        int even_even = 0;
        int odd_even = 0;

        for (int i =0 ; i<n ; i++){
            if (arr[i]%2!=0){
                odd++;
            }
            else{
                if ((arr[i]/2)%2!=0){
                    odd_even++;
                }
                else even_even++;
            }
        }

        cout<<maximun(odd, even_even, odd_even)<<endl;
    }

    return 0;
}