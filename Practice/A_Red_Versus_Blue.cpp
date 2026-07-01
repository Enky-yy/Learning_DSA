#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, r, b;
        cin >> n >> r >> b;
        string s;
        long rmax = 0;
        long long divide = r / (b + 1);
        long long additional = r%(b+1);
        long long r_count = 0;
        for (int i = 1; i <= b+1; i++)
        {
            
            for (int  i = 0; i < divide; i++)
            {
                s+='R';
            }
            if(additional>0){
                s+='R';
                additional--;
            }
            if(i!=b+1){
                s+='B';
            }
            
        }
        cout<<s<<endl;
    }

    return 0;
}