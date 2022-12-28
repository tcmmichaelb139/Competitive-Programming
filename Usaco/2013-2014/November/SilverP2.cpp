#include "bits/stdc++.h"
using namespace std;

int n, d;
vector<pair<int, int>> v;

vector<bool> solve() {
    vector<bool> sol(n);
    set<int> ind;
    set<pair<int, int>> cur;
    for (int i = 0; i < n; i++) {
        while (ind.size() && abs(v[i].first - v[*begin(ind)].first) > d) {
            cur.erase({v[*begin(ind)].second, v[*begin(ind)].first});
            ind.erase(begin(ind));
        }

        if (cur.size()) {
            int k = (*--end(cur)).first;

            if (k >= v[i].second * 2)
                sol[i] = true;
        }

        cur.insert({v[i].second, v[i].first});
        ind.insert(i);
    }
    return sol;
}

int main() {
    freopen("crowded.in", "r", stdin);
    freopen("crowded.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> d;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }

    sort(begin(v), end(v));
    vector<bool> sol1 = solve();
    sort(rbegin(v), rend(v));
    vector<bool> sol2 = solve();

    int ans = 0;
    for (int i = 0; i < n; i++)
        if (sol1[i] && sol2[n - i - 1])
            ans++;
    cout << ans << '\n';
}
