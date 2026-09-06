#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    string s;
    cin>>s;
    int cnts=1;
    int maxi =1;
    for(int i =1 ; i<s.size() ; i++){
        if(s[i]==s[i-1]){
            cnts++;
        }
        else{
            cnts=1;
        }
        maxi = max(maxi, cnts);
    }
    cout<<maxi<<endl;
    return 0;
}