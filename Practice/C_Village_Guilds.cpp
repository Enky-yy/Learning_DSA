#include <bits/stdc++.h>
using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {
         int n;
    cin >> n;

    vector<vector<int>> nodes(n + 1);

    for (int i = 2; i <= n; i++) {
        int k;
        cin >> k;
        nodes[k].push_back(i);
    }

    vector<int> height(n + 1, 0);
    vector<int> order;
    stack<int> st;
    st.push(1);

    while (!st.empty()) {
        int j = st.top();
        st.pop();
        order.push_back(j);

        for (int node : nodes[j])
            st.push(node);
    }

    reverse(order.begin(), order.end());

    for (int o : order) {
        for (int node : nodes[o]) {
            height[o] = max(height[o], height[node] + 1);
        }
    }

    long long ans = n; 

    for (int i = 1; i <= n; i++) {
        if (nodes[i].size() >= 2) {
            int first = -1, second = -1;

            for (int node : nodes[i]) {
                int h = height[node];
                if (h >= first) {
                    second = first;
                    first = h;
                } else if (h > second) {
                    second = h;
                }
            }

            ans += second + 1;
        }
    }

    cout << ans << '\n';
    }

    return 0;
}