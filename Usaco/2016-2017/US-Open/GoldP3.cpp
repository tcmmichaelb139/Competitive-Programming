#include "bits/stdc++.h"
using namespace std;

int main() {
    freopen("art2.in", "r", stdin);
    freopen("art2.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> v(n);
    map<int, int> num;
    vector<int> f(n + 1, -1);
    for (int i = 0; i < n; i++) {
        cin >> v[i], num[v[i]]++;
        if (f[v[i]] == -1)
            f[v[i]] = i;
    }

    auto check = [&]() {
        vector<bool> added(n + 1, false), in(n + 1, false);
        stack<int> s;
        for (auto a : v) {
            if (added[a]) {
                while (s.size() && s.top() != a) {
                    if (s.top() == 0) return false;
                    if (!in[s.top()] || !in[a]) return false;
                    in[s.top()] = false;
                    s.pop();
                }
                in[a] = true;
            } else
                s.push(a), added[a] = true, in[a] = true;
        }
        return true;
    };

    stack<pair<int, int>> sol;

    for (auto i : v) {
        if (i == 0) {
            int mx = 0;
            while (sol.size()) {
                mx = max(mx, sol.top().first);
                sol.pop();
            }
            sol.push({mx, f[i]});
        } else if (--num[i] == 0) {
            int mx = 0;
            while (sol.size() && sol.top().second > f[i]) {
                mx = max(mx, sol.top().first);
                sol.pop();
            }

            sol.push({mx + 1, f[i]});
        }
    }

    int ans = 0;
    while (sol.size()) {
        ans = max(ans, sol.top().first);
        sol.pop();
    }
    if (check())
        cout << ans << '\n';
    else
        cout << -1 << '\n';
}
