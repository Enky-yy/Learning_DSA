#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    int low = 1;
    int high = (n /2) + 1;
    int i = 0;
    if (n == 1)
        cout << 1 << endl;
    else if (n <= 3)
    {
        cout << "NO SOLUTION" << endl;
    }
    else
    {
        while (i < n)
        {
            if (i % 2 == 0)
            {
                cout << high << " ";
                high++;
            }
            else
            {
                cout << low << " ";
                low++;
            }
            i++;
        }
    }

    return 0;
}