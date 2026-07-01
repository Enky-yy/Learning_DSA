#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int prime_factor=0;
        int factors = 0;
        int i=2;

        while (i*i<=n)
        {
            if(n%i==0){
                prime_factor+=1;
                while (n%i==0)
                {
                    factors++;
                    n /=i;
                }
                
            }
            i++;
        }
        if(n>1){
            prime_factor++;
            factors++;
        }
        cout<<prime_factor+factors-1<<endl;
        
    }

    return 0;
}