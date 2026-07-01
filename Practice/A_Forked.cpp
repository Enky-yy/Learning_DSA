#include <bits/stdc++.h>

using namespace std;

bool distances(vector<long long> a , vector<long long>b){
    double x = ((a[0]- b[0]) * (a[0]-b[0]));
    double y = ((a[1]- b[1]) * (a[1]-b[1]));
    return sqrt(x+y)==sqrt(5);
}

int main() {
    
    int t;
    cin>>t;
    while (t--)
    {
        vector<long long> h(2), k(2), q(2);
        for (int i = 0; i < 2; i++)
        {
            cin>>h[i];
        }
        for (int i = 0; i < 2; i++)
        {
            cin>>k[i];
        }
        for (int i = 0; i < 2; i++)
        {
            cin>>q[i];
        }
        long moves=0;
        if(distances(h, k))
            moves++;
        if(distances(h,q))
            moves++;
        cout<<moves<<endl;
    }
    
    return 0;
}