#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n, p;
    cin >> n >> p;
    vector<int> t(n);

    for (int i = 0; i < n; i++)
    {
        cin >> t[i];
    }
    sort(t.begin(), t.end());
    int left = -1, right = n - 1;
    int count = 0;
    int team_size=1;
    while (left < right)
    {
        if (t[right] * (team_size) <= p )
        {
            left++;
            team_size++;
        }
        else if (t[right] * (team_size) > p )
        {
            count++;
            right--;
            team_size=1;
        }
    }
    cout << count << endl;

    return 0;
}