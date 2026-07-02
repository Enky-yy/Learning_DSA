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
        long long moves = 0;
        bool check = true;
        while (n > 1)
        {
            if (n == 1)
                break;
            if (n % 6 == 0)
            {
                moves++;
                n = n / 6;
            }
            else if (n % 3 != 0)
            {
                check = false;
                break;
            }
            else
                {n *= 2;
                moves++;}
        }
        if(check)
            cout<<moves<<endl;
        else
            cout<<-1<<endl;
    }

    return 0;
}