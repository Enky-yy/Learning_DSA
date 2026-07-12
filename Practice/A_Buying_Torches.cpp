#include <bits/stdc++.h>

using namespace std;

long long ceil_division(long long a, long long b) {
	return (a + b - 1) / b;
}

int main() {
    int t;
    cin>>t;
    while (t--)
    {
        long long x,y,n;
        cin>>x>>y>>n;
        long long total = (y*n)+n;
        long long needed = total-1;
        long long count =n + ceil_division(needed, x-1);
        cout<<count<<endl;

    }
    
    return 0;
}