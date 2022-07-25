#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    stack<pair<long long, int>> s;
    s.push({-1, 0});
    vector<long long> l(n), r(n), v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];

        while (!s.empty() && s.top().first >= v[i])
            s.pop();

        l[i] = s.top().second;

        s.push({v[i], i + 1});
    }

    while (!s.empty()) s.pop();
    s.push({-1, n});

    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && s.top().first >= v[i])
            s.pop();

        r[i] = s.top().second;

        s.push({v[i], i});
    }

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, v[i] * (r[i] - l[i]));
    }
    cout << ans << '\n';
}
