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
        string s;
        cin >> s;

        long long continous  = 0;
        for (int i = 0; i + 1 < n; i++)
        {
            if (s[i] != s[i + 1])
                continous++;
        }

        if(continous==1){
            cout<<2<<endl;
        }
        else{
            cout<<1<<endl;
        }
    }

    return 0;
}