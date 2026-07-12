#include <bits/stdc++.h>

using namespace std;

string Alien(string adj[], int n, int k)
{
    for (int i = 0; i < n - 1; i++)
    {
        vector<int> adjls[k];
        string s1 = adj[i];
        string s2 = adj[i + 1];

        int len = min(s1.size(), s2.size());

        int start = 0;
        while (start < len)
        {
            if (s1[start] != s2[start])
            {
                adjls[s1[start] - 'a'].push_back(s2[start] - 'a');
                break;
            }
            start++;
        }
    }
}
int main()
{

    return 0;
}