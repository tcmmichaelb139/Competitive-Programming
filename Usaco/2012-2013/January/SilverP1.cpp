#include "bits/stdc++.h"
using namespace std;

int main() {
    freopen("paint.in", "r", stdin);
    freopen("paint.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        int a;
        char c;
        cin >> a >> c;
        if (c == 'L') a = -a;
        v[i] = a;
    }

    set<int> points;
    vector<int> cur(n + 1);
    cur[0] = 0;
    points.insert(0);

    for (int i = 0; i < n; i++) {
        cur[i + 1] = cur[i] + v[i];
        points.insert(cur[i + 1]);
    }

    map<int, int> m, m_rev;
    int tmp = 0;
    for (auto i : points)
        m[i] = tmp, m_rev[tmp] = i, tmp++;

    vector<int> pre(tmp + 1, 0);
    pre[tmp] = -1e9;
    for (int i = 0; i < n; i++) {
        if (cur[i] > cur[i + 1])
            pre[m[cur[i + 1]]]++, pre[m[cur[i]]]--;
        else
            pre[m[cur[i]]]++, pre[m[cur[i + 1]]]--;
    }

    int ans = 0;
    int start = -1;
    for (int i = 0; i <= tmp; i++) {
        if (i)
            pre[i] += pre[i - 1];
        if (pre[i] >= k) {
            if (start == -1)
                start = i;
        } else if (start != -1) {
            ans += m_rev[i] - m_rev[start];
            start = -1;
        }
    }
    cout << ans << '\n';
}
