#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> majorityelement(vector<int> &a)
{
    int cnt1 = 0;
    int cnt2 = 0;
    int el1 = INT_MIN;
    int el2 = INT_MIN;
    for (int i = 0; i < a.size(); i++)
    {
        if (cnt1 == 0 && el2 != a[i])
        {
            cnt1++;
            el1 = a[i];
        }
        else if (cnt2 == 0 && el1 != a[i])
        {
            cnt2++;
            el2 = a[i];
        }
        else if (a[i] == el1)
        {
            cnt1++;
        }
        else if (a[i] == el2)
        {
            cnt2++;
        }
        else
        {
            cnt1--;
            cnt2--;
        }
    }
    vector<int> ls;
    cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == el1)
            cnt1++;
        if (a[i] == el2)
            cnt2++;
    }

    int mini = (int)(a.size() / 2) + 1;
    if (cnt1 >= mini)
        ls.push_back(el1);
    if (cnt2 >= mini)
        ls.push_back(el2);
    sort(ls.begin(), ls.end());
    return ls;
}

int main()
{

    return 0;
}