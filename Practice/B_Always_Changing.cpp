#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    int t;
    cin >> t;
    while (t--)

    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int counts =1;
        int zeroes=0;
        int ones =0;

       
        for (int i = 1; i < n; i++)
        {
            if (s[i] != s[i-1])
            {
                counts++;
            }
            else{
                if(s[i]=='1')
                    ones++;
                else
                    zeroes++;
            }
        }

        if (counts < 2)
            cout << -1 << endl;
        else if(abs(zeroes-ones)>=2){
            cout<<n-counts+abs(zeroes-ones)-1<<endl;
        }
        else
            cout << n - counts << endl;
    }
    return 0;
}