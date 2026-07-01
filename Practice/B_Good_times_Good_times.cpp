#include <iostream>
using namespace std;

int main() {

    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        long long length = s.length();

        long long ans = 1;
        for (int i = 0; i < length; i++) {
            ans *= 10;
        }
        ans += 1;

        cout << ans << '\n';
    }

    return 0;
}