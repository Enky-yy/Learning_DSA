#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n;
    cin >> n;

    string s;
    cin >> s;

    long long check = 0;
    for (long long i = 0; i < n - 1; i++)
    {
        if (s[i] > s[i + 1])
        {
            swap(s[i],s[i+1]);
            cout<<"YES"<<endl;
            cout<<i+1<<" "<<i+2<<endl;
            check =1;
            break;
        }
    }
    if(check!=1)
        cout<<"NO"<<endl;

    return 0;
}