#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        if (n == 1)
            cout << 1 << endl;
        else if (n == 2)
        {
            cout << -1 << endl;
            continue;
        }
        else
        {
            long long sum = 6;
            vector<long long> ans ={1,2,3};
            for (long long i = 4; i <=n; i++)
            {
                ans.push_back(sum);
                sum*=2;
            }
            

            for (auto it : ans)
            {
                cout << it << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
