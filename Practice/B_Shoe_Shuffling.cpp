#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin>>t;
    while (t--)
    {
        long long n;
        cin>>n;
        vector<long long>a(n);
        for (int i = 0; i < n; i++)
        {
            cin>>a[i];
            
        }
        map<long long, long long> freq; 
		for (int i = 0; i < n; i++) 
			freq[a[i]]++;

		long long count = 0; 
		for (auto i : freq)
		{
			if (i.second == 1)
			{
				count = 1;
				break;
			}
		}
        if(count==1) {cout<<-1<<endl; continue;}

        vector<long long > student(n);
        for (int i = 0; i < n; i++)
        {
            student[i] = i+1;
        }
        int l=0 , r=0;
        while (r<n)
        {
            if(a[l]==a[r])
                r++;
            else{
                rotate(student.begin()+l , student.begin()+l+1, student.begin()+r);
                l=r;
            }
        }
        rotate(student.begin() + l, student.begin() + l + 1, student.begin() + r);

        for(auto it:student){
            cout<<it<<" ";
        }
        cout<<endl;

        
        
        
        
    }
    
    return 0;
}