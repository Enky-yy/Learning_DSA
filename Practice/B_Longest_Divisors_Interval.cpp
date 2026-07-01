#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin>>t;
    while (t--)
    {
        long long n;
        cin>>n;
        long long lowest = 1;
        long long highest =1;
		while (n % highest == 0) 
			highest++;
		cout << highest - 1 << endl;
        
    }
    
    return 0;
}