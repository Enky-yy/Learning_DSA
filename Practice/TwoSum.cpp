#include <bits/stdc++.h>

using namespace std;
void TwoSum(vector<int> &a, int k, int n)
{
    int low = 0;
    int right = n - 1;
    bool ifExist = false;
    while (low < right)
    {
        int sum = a[low] + a[right];
        if (sum > k)
        {
            right--;
        }
        else if (sum < k)
        {
            low++;
        }
        else
        {
            ifExist = true;
            break;
        }
    }
    if (ifExist)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}
int main()
{

    return 0;
}