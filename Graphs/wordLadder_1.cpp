#include <bits/stdc++.h>

using namespace std;

int words(vector<string> &wordlist, string start, string target)
{
    queue<pair<string, int>> q;
    q.push({start, 1});
    unordered_set<string> st(wordlist.begin(), wordlist.end());
    st.erase(start);
    while (!q.empty())
    {
        string word = q.front().first;
        int len = q.front().second;
        q.pop();
        if (word == target)
            return len;

        for (int i = 0; i < word.size(); i++)
        {
            char original = word[i];
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                word[i] = ch;
                if (st.find(word) != st.end())
                {
                    st.erase(word);
                    q.push({word, len + 1});
                }
            }
            word[i] = original;
        }
    }
    return 0;
}

int main()
{

    return 0;
}