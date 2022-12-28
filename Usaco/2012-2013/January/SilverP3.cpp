#include "bits/stdc++.h"
using namespace std;

int n, g;
vector<set<int>> v;
map<int, vector<int>> m;
map<int, bool> vis;
int ans = 0;

void solve(int k) {
    if (vis[k]) return;
    vis[k] = true;
    for (auto i : m[k]) {
        v[i].erase(k);
        if (v[i].size() == 1)
            solve(*v[i].begin());
    }
    m.erase(k);
    ans++;
}

int main() {
    freopen("invite.in", "r", stdin);
    freopen("invite.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> g;
    for (int i = 0; i < g; i++) {
        int x;
        cin >> x;
        set<int> s;
        for (int j = 0; j < x; j++) {
            int a;
            cin >> a;
            m[a].push_back(i);
            s.insert(a);
        }
        v.push_back(s);
    }

    solve(1);
    cout << ans << '\n';
}
