#include "bits/stdc++.h"
using namespace std;

struct cow {
    int i;
    long long a;
    long long t;

    bool operator<(const cow &rhs) const {
        return i < rhs.i;
    }
};

int main() {
    freopen("convention2.in", "r", stdin);
    freopen("convention2.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<cow> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i].a >> v[i].t, v[i].i = i;

    sort(begin(v), end(v), [](cow a, cow b) { if (a.a == b.a) return a.i < b.i; return a.a < b.a; });

    set<cow> c;

    long long ans = 0;

    long long time = v[0].a + v[0].t;

    int i = 1;

    while (i < n) {
        if (v[i].a <= time) {
            c.insert(v[i++]);
            continue;
        }
        if (size(c)) {
            auto it = begin(c);
            ans = max(ans, time - it->a);
            time += it->t;
            c.erase(it);
        } else {
            time = v[i].a + v[i].t;
            i++;
        }
    }

    while (size(c)) {
        auto it = begin(c);
        ans = max(ans, time - it->a);
        time += it->t;
        c.erase(it);
    }

    cout << ans << '\n';
}
