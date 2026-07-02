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
        long long ones = 0;
        long long zeros = 0;
        for (long long i = 0; i < s.size(); i++)
        {
            if (s[i] == '0')
                zeros++;
            if (s[i] == '1')
                ones++;
        }
        long long total = 0;
        total = double(s.size() - abs(ones - zeros))/2;
        if (total % (2) == 0)
            cout << "NET" << endl;
        else
            cout << "DA" << endl;
    }

    return 0;
}