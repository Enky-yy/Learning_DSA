#include <bits/stdc++.h>

using namespace std;

const long long mod = 1000000007;
typedef long long ll;
const long long maxi = 200005;

int main()
{

    vector<long long> pow(maxi);
    pow[0] = 1;
    for (long long i = 1; i < maxi; i++)
    {
        pow[i] = (pow[i - 1] * 2) % mod;
    }
    long long t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        vector<long long> a(n);
        for (long long i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        long long negatives = 0;
        long long i = 0;
        while (i < n && a[i] == -1)
        {
            negatives++;
            i++;
        }

        vector<long long> positives;
        for (long long j = i; j < n; j++)
        {
            positives.push_back(a[j]);
        }

        long long n2 = positives.size();
        long long power = 0;
        long long cntsPairs = 0;
        long long j = 0;
        long long previous = -1;
        bool check = false;

        while (j < n2)
        {
            long long temp = positives[j];
            long long idx = j;
            while (idx < n2 && positives[idx] == temp)
            {
                idx++;
            }
            power++;
            if (check && temp- previous == 1)
                cntsPairs++;
            previous = temp;
            check = true;
            j = idx;
        }

        long long without = pow[n2-power];
        long long minuss = (without * cntsPairs)%mod;

        if(negatives==0)
            cout<<without<<endl;
        else
            cout<< (pow[negatives-1]* ((without+minuss) % mod)) % mod<<endl;
        
    }

    return 0;
}