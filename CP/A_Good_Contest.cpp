#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x;
        cin >> x;
        // cout<<x<<endl;
        vector<int> arr(3);
        for (int i = 0; i < 3; i++)
        {
            cin >> arr[i];
        }
        int mini = arr[0];
        for (int i = 1; i < 3; i++)
        {
            if (mini > arr[i])
            {
                mini = arr[i];
            }
        }

        cout << x - mini << endl;
    }

    return 0;
}