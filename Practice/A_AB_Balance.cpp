#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        long long t = s.size();

        while (s[0]!=s[t-1])
        {
            if(s[0]=='a')
                s[0]='b';
            else
                s[0]='a';
        }
        cout<<s<<endl;
        
            
        
    }

    return 0;
}