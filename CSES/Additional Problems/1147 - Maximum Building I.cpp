#include "bits/stdc++.h"
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    vector<queue<int>> row(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        for (int j = 0; j < m; j++)
            if (v[i][j] == '*')
                row[i].push(j);
    }
    for (int i = 0; i < n; i++)
        row[i].push(m);

    int ans = 0;
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++)
            if (row[i].front() < j)
                row[i].pop();

        vector<int> l(n), r(n);
        stack<pair<int, int>> s;
        s.push({-1, 0});
        for (int i = 0; i < n; i++) {
            while (!s.empty() && row[i].front() - j <= s.top().first)
                s.pop();

            l[i] = s.top().second;
            s.push({row[i].front() - j, i + 1});
        }
        while (!s.empty()) s.pop();
        s.push({-1, n});
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && row[i].front() - j <= s.top().first)
                s.pop();

            r[i] = s.top().second;
            s.push({row[i].front() - j, i});
        }
        for (int i = 0; i < n; i++) {
            ans = max(ans, (row[i].front() - j) * (r[i] - l[i]));
        }
    }
    cout << ans << '\n';
}
