// // // #include <bits/stdc++.h>

// // // using namespace std;

// // // int main() {
// // //     int t;
// // //     cin>>t;
// // //     while (t--)
// // //     {
// // //         long long n;
// // //         cin>>n;
// // //         string s;
// // //         cin>>s;
// // //         long long inversions = 0;
// // //         vector<long long> one;
// // //         long long counter=1;

// // //         for (long long i = 0; i < n-1; i++)
// // //         {
// // //            if(s[i]=='1')
// // //             one.push_back(i);
// // //         }
// // //         for (long long i = one[i]; i < n-1; i++)
// // //         {
// // //             if(s[i+1]=='0'){
// // //                 inversions++;
// // //             }
// // //             if(i==(n-2)){
// // //                 i = one[counter];
// // //                 counter++;
// // //             }
// // //         }

// // //         if(inversions%2==0){
// // //             cout<<"BOB"<<endl;
// // //         }
// // //         else
// // //             cout<<"ALICE"<<endl;

// // //     }

// // //     return 0;
// // // }

// // #include <bits/stdc++.h>
// // using namespace std;

// // int main()
// // {
// //     int t;
// //     cin >> t;

// //     while (t--)
// //     {
// //         long long n;
// //         cin >> n;

// //         string s;
// //         cin >> s;

// //         vector<long long> one;
// //         for (long i = 0; i < n; i++)
// //         {
// //             if (s[i] == '1')
// //                 one.push_back(i);
// //         }

// //         if (one.size() == 1)
// //         {
// //             cout << "Alice\n";
// //         }
// //         else if (one.size() == 0)
// //         {
// //             cout << "Bob\n";
// //         }

// //         else if(one.size()<n)
// //         {

// //             long long inversions = 0;

// //             for (long long idx : one)
// //             {
// //                 for (long long j = idx + 1; j < n; j++)
// //                 {
// //                     if (s[j] == '0')
// //                         inversions++;
// //                 }
// //             }

// //             if (inversions % 2 == 0)
// //                 cout << "Bob\n";
// //             else
// //                 cout << "Alice\n";
// //         }
// //     }
// //     return 0;
// // }

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {

//     int t;
//     cin >> t;

//     while (t--)
//     {
//         long long n;
//         cin >> n;

//         string s;
//         cin >> s;

//         vector<long long> one;
//         for (int i = 0; i < n-1; i++)
//         {
//             if (s[i] == '1')
//                 one.push_back(i);
//         }

//         // All zeros
//         if (one.empty())
//         {
//             cout << "Bob\n";
//             continue;
//         }

//         // Exactly one '1'
//         if (one.size() == 1)
//         {
//             cout << "Alice\n";
//             continue;
//         }

//         // All ones
//         if (one.size()+1 == n)
//         {
//             cout << "Bob\n";
//             continue;
//         }

//         long long inversions = 0;
//         long long ones = 0;

//         for (char c : s)
//         {
//             if (c == '1')
//                 ones++;
//             else
//                 inversions += ones;
//         }

//         if (inversions % 2)
//             cout << "Alice\n";
//         else
//             cout << "Bob\n";
//     }

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        string s;
        cin >> s;

        vector<pair<char, int>> arr;

        for (char c : s) {
            if (arr.empty() || arr.back().first != c)
                arr.push_back({c, 1});
            else
                arr.back().second++;
        }

        if (!arr.empty() && arr.front().first == '0')
            arr.erase(arr.begin());

        if (!arr.empty() && arr.back().first == '1')
            arr.pop_back();

        if (arr.empty()) {
            cout << "Bob\n";
            continue;
        }

        bool allEven = true;
        for (auto &[ch, len] : arr) {
            if (len % 2 != 0) {
                allEven = false;
                break;
            }
        }

        if (allEven)
            cout << "Bob\n";
        else
            cout << "Alice\n";
    }

    return 0;
}