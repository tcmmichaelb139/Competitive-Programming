#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> b(n + 1);
    vector<vector<int>> pos(k + 1);
    vector<vector<int>> adj(k + 1);
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        pos[b[i]].push_back(i);
    }

    for (int i = 0; i < k; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < k; j++)
            if (s[j] == '1')
                adj[i + 1].push_back(j + 1);
    }

    vector<int> dist(n + 1, 1e9);

    vector<int> in(n + 1, -1);
    set<pair<int, int>> s;
    s.insert({0, 1});
    in[1] = 0;
    while (!s.empty()) {
        pair<int, int> v = *begin(s);
        s.erase(begin(s));

        if (dist[v.second] <= v.first) continue;
        dist[v.second] = v.first;
        if (v.second == n) break;

        for (int i : adj[b[v.second]]) {
            for (int u : pos[i]) {
                if (u == v.second) continue;
                int total = v.first + abs(v.second - u);
                if (dist[u] <= total)
                    continue;

                if (in[u] <= total && in[u] != -1)
                    continue;
                else if (s.find({in[u], total}) != s.end())
                    s.erase({in[u], total});
                s.insert({total, u});
                in[u] = total;
            }
        }
    }

    cout << (dist[n] == (int)(1e9) ? -1 : dist[n]) << '\n';
}
