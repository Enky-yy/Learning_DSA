#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> teleport(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> teleport[i];
    }

    while (m--)
    {
        int start, k;
        cin >> start >> k;
        queue<int> q;
        q.push(start);

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            if(k==0){
                cout<<node<<endl;
                break;
            }
            k--;
            if (node == teleport[node]){
                cout<<node<<endl;
                break;
            }
            q.push(teleport[node]);
        }
    }

    return 0;
}