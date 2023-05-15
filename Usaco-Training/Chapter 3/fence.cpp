/*
ID: tcmmich1
TASK: fence
LANG: C++
 */
#include "bits/stdc++.h"
using namespace std;

vector<pair<int, int>> adj[501];
vector<pair<int, int>>::iterator itx[501];

int main() {
    freopen("fence.in", "r", stdin);
    freopen("fence.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<bool> used;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        int m = size(used);
        adj[a].push_back({b, m});
        adj[b].push_back({a, m});
        used.push_back(false);
    }

    for (int i = 0; i <= 500; i++) {
        sort(begin(adj[i]), end(adj[i]));
        itx[i] = begin(adj[i]);
    }

    int start = -1;
    for (int i = 0; i <= 500; i++) {
        if (size(adj[i]) == 0) continue;
        if (size(adj[i]) & 1) {
            start = i;
            break;
        } else if (start == -1)
            start = i;
    }

    assert(start != -1);
    vector<pair<pair<int, int>, int>> s = {{{start, -1}, -1}}, ret;

    while (!s.empty()) {
        int v = s.back().first.first;
        auto it = itx[v];
        auto en = end(adj[v]);
        while (it != en && used[it->second]) it++;
        if (it == en) {
            ret.push_back(s.back());
            s.pop_back();
        } else {
            s.push_back({{it->first, v}, it->second});
            used[it->second] = true;
        }
    }

    vector<int> ans;
    for (auto i : ret)
        ans.push_back(i.first.first);

    reverse(begin(ans), end(ans));

    for (int i = 0; i < size(ans); i++)
        cout << ans[i] << '\n';
}
