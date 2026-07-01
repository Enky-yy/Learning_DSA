#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        string c;
        string s;
        cin >> n;
        cin >> c;
        cin >> s;
        long long index = -1;
        n*=2;
        s+=s;
        long long maxi=INT_MIN;
        for (long long i = n-1; i >=0; i--)
        {
            
            if (s[i] == 'g')
            {
                index = i;
            }
            if(s[i]==c[0]){
                long long difference = index-i;
                maxi = max(maxi, difference);
            }
        }
        cout<<maxi<<endl;
       

        
    }

    return 0;
}