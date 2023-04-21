#include "bits/stdc++.h"
using namespace std;

struct node {
    int v;
    long long time;
    int prev;

    bool operator<(const node &rhs) const {
        return time > rhs.time;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, M, S, T, U, V;
    cin >> N >> M >> S >> T >> U >> V;
    vector<pair<int, long long>> adj[N + 1];
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    auto distcalc = [&](int s) {
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;
        vector<long long> dist(N + 1, 1e18);
        vector<bool> vis(N + 1);

        q.push({0, s});
        while (!q.empty()) {
            pair<long long, int> v = q.top();
            q.pop();

            if (vis[v.second]) continue;
            vis[v.second] = true;

            dist[v.second] = v.first;

            for (auto u : adj[v.second]) {
                q.push({u.second + v.first, u.first});
            }
        }

        return dist;
    };

    vector<long long> fu = distcalc(U), fv = distcalc(V);

    auto anscalc = [&](int s, int e) {
        priority_queue<node> q;
        vector<bool> vis(N + 1);
        vector<long long> mtu(N + 1, 1e18), mtv(N + 1, 1e18), sol(N + 1, 1e18);

        q.push({s, 0, s});

        while (!q.empty()) {
            node v = q.top();
            q.pop();

            if (vis[v.v]) {
                if (sol[v.v] == v.time)
                    if (min(mtu[v.prev], fu[v.v]) + min(mtv[v.prev], fv[v.v]) < mtu[v.v] + mtv[v.v]) {
                        mtu[v.v] = min(fu[v.v], mtu[v.prev]);
                        mtv[v.v] = min(fv[v.v], mtv[v.prev]);
                    }
                continue;
            }
            vis[v.v] = true;
            sol[v.v] = v.time;

            mtu[v.v] = min(fu[v.v], mtu[v.prev]);
            mtv[v.v] = min(fv[v.v], mtv[v.prev]);

            for (auto u : adj[v.v]) {
                q.push({u.first, v.time + u.second, v.v});
            }
        }

        return mtu[e] + mtv[e];
    };

    cout << min(min(anscalc(S, T), anscalc(T, S)), fu[V]) << '\n';
}
