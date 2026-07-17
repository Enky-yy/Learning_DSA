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

        if (n == 1)
        {
            int x;
            cin >> x;
            cout << "YES" << endl;
            continue;
        }

        vector<long long> p(n+2);
        for (long long i = 2; i <=n; i++)
        {
            cin>>p[i];
        }

        vector<long long>a(n+1);
        for (long long i = 1; i <=n; i++)
        {
            cin>>a[i];
        }

        vector<vector<long long>> children(n+1);
        for (long long i = 2; i <=n; i++)
        {
            children[p[i]].push_back(i);
        }


        vector<long long> order;
        queue<long long>q;
        q.push(1);

        while (!q.empty())
        {
            /* code */
        }
        
        
        
        
    }

    return 0;
}