#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin>>t;
    while (t--)
    {
        string s;
        cin>>s;
        string k;
        cin>>k;
        long long sl = s.size();
        long long kl = k.size();
        vector<long long> frequency(26,0);
        for (int i = 0; i < kl; i++)
        {
            frequency[k[i]-'A']++;
        }
        for (int i = sl-1; i >=0; i--)
        {
            if(frequency[s[i]-'A']>0)
                frequency[s[i]-'A']--;
            else
                s[i]='.';
        }
        string final = "";
        for (int i = 0; i < sl; i++)
        {
            if(s[i]!='.')
                final+=s[i];
        }
        if(k==final)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
        
        
        
    }
    
    return 0;
}