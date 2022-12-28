#include "bits/stdc++.h"
using namespace std;

int main() {
    freopen("msched.in", "r", stdin);
    freopen("msched.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    map<int, vector<int>> m;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        m[b].push_back(a);
    }

    int ans = 0;
    multiset<int, greater<int>> s;
    for (int i = 10001; i >= 0; i--) {
        if (s.size()) {
            ans += *s.begin();
            s.erase(s.begin());
        }

        for (auto j : m[i])
            s.insert(j);
    }

    cout << ans << '\n';
}
