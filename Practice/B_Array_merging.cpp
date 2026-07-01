#include <bits/stdc++.h>

using namespace std;

// int main() {
//     int t;
//     cin>>t;
//     while (t--)
//     {
//         int n;
//         cin>>n;
//         int ans=1;
//         vector<int> a(n), b(n);
//         map<int , int> mpp;
//         for(auto it: a){
//             cin>>it;
//             mpp[it]++;
//         }
//         for(auto it:b){
//             cin>>it;
//             mpp[it]++;
//         }
//         for(auto it:mpp){
//             ans = max(it.second, ans);
//         }
//         cout<<ans<<endl;
//     }
    
//     return 0;
// }

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n ;
        cin>>n;
        vector<long long> a(n), b(n);
        for (long long i = 0; i < n; i++)
        {
            cin>>a[i];
        }
        for (long long i = 0; i < n; i++)
        {
            cin>>b[i];
        }

        vector<long long > sub_a(2*n+1 , 0);
        vector<long long > sub_b(2*n+1 , 0);

        long long counter=1;

        for (long long i = 1; i < n; i++)
        {
            if(a[i]==a[i-1])
                counter++;
            else{
                sub_a[a[i-1]] = max(sub_a[a[i-1]], counter);
                counter=1;
            }
        }
        sub_a[a[n-1]]= max(sub_a[a[n-1]], counter);

        counter=1;

        for (long long i = 1; i < n; i++)
        {
            if(b[i]==b[i-1])
                counter++;
            else{
                sub_b[b[i-1]] = max(sub_b[b[i-1]], counter);
                counter=1;
            }
        }
        sub_b[b[n-1]]= max(sub_b[b[n-1]], counter);
        

        long long maxi =-1;

        for (long long i = 1; i <=2* n; i++)
        {
            maxi = max(maxi, sub_a[i]+ sub_b[i]);
        }


        cout<<maxi<<endl;
         
    }
    return 0;
    
}