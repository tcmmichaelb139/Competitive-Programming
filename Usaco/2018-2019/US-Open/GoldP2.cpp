#include "bits/stdc++.h"
using namespace std;

int main() {
    freopen("walk.in", "r", stdin);
    freopen("walk.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n, k;
    cin >> n >> k;

    vector<bool> vis(n, false);

    vector<long long> dist(n, 2019201997);

    for (int i = 0; i < n; i++) {
        long long v = -1;
        for (long long j = 0; j < n; j++)
            if (!vis[j] && (v == -1 || dist[v] > dist[j]))
                v = j;

        vis[v] = true;
        for (long long u = 0; u < n; u++) {
            if (vis[u]) continue;
            dist[u] = min(dist[u], (2019201913ll * min(v + 1, u + 1) + 2019201949ll * max(v + 1, u + 1)) % 2019201997ll);
        }
    }

    sort(begin(dist), end(dist));

    cout << dist[n - k] << '\n';
}
