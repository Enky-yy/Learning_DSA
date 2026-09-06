#include <bits/stdc++.h>
using namespace std;

void hanoi(int n, char source, char helper, char destination) {
    if (n == 1) {
        cout << source << " " << destination << '\n';
        return;
    }

    // Move n-1 disks from source to helper
    hanoi(n - 1, source, destination, helper);

    // Move largest disk from source to destination
    cout << source << " " << destination << '\n';

    // Move n-1 disks from helper to destination
    hanoi(n - 1, helper, source, destination);
}

int main() {
    int n;
    cin >> n;

    cout << (1LL << n) - 1 << '\n';

    hanoi(n, '1', '2', '3');

    return 0;
}