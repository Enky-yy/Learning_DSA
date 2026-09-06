#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    vector<int> freq(26, 0);

    for (char c : s) {
        freq[c - 'A']++;
    }

    int odd = 0;
    int oddChar = -1;

    for (int i = 0; i < 26; i++) {
        if (freq[i] % 2 != 0) {
            odd++;
            oddChar = i;
        }
    }

    // More than one odd frequency -> impossible
    if (odd > 1) {
        cout << "NO SOLUTION\n";
        return 0;
    }

    string left;

    // Build the left half
    for (int i = 0; i < 26; i++) {
        left += string(freq[i] / 2, 'A' + i);
    }

    // Right half is reverse of left
    string right = left;
    reverse(right.begin(), right.end());

    // Middle character if length is odd
    if (oddChar != -1) {
        cout << left;
        cout << char('A' + oddChar);
        cout << right;
    } else {
        cout << left << right;
    }

    cout << '\n';

    return 0;
}