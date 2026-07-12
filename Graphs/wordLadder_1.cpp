#include <bits/stdc++.h>

using namespace std;

int words(string s[], string start, string target)
{
    int n = s->size();
    int m = s[0].size();

    int starting = 0;
    for (int i = 0; i < m; i++)
    {
        if (start[i] != target[i])
        {
            starting = i;
            break;
        }
    }
    int counts = 1;
    
}

int main()
{

    return 0;
}