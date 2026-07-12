#include <bits/stdc++.h>

using namespace std;

int main() {
    long long t;
    cin>>t;
    while (t--)
    {
        long long n;
        cin>>n;
        vector<long long> a(n);
        for (long long i = 0; i < n; i++)
        {
            cin>>a[i];
        }

        vector<long long> prefixOne(n), prefixTwo(n);

        long long one=0, two=0;
        for (long long i = 0; i < n; i++)
        {
            if(a[i]==1)
                {
                    one++;
                    two++;
                }
            else if (a[i]==2)
            {
                one--;
                two++;
            }
            else{
                one--;
                two--;
            }
            prefixOne[i]=one;
            prefixTwo[i]=two;
            
        }

        vector<long long> suffixThree(n+1);

        suffixThree[n-2]=prefixTwo[n-2];

        for (long long i = n-3; i >=0; i--)
        {
            suffixThree[i]= max(suffixThree[i+1], prefixTwo[i]);
        }

        bool check = true;

        for (long long i = 0; i <=n-3; i++)
        {
            if(suffixThree[i+1]>=prefixTwo[i] && prefixOne[i]>=0)
                {check=false;
                break;}
        }


        cout<<(check ? "NO" : "YES")<<endl;
        
        
        
        
    }
    
    return 0;
}