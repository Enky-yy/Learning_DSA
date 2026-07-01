#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin>>t;
    while (t--)
    {
        long long n ;
        cin>>n;
        string s;
        cin>>s;
        long long left = 0;
        long long right =n-1;
        while (left<right)
        {
            if(s[left]=='1' && s[right]=='0'){
                left++;
                right--;
            }
            else if(s[right]=='1' && s[left]=='0'){
                right--;
                left++;
            }
            else{
                break;
            }
        }
        cout<<right-left+1<<endl;
        
        
    }
    
    return 0;
}