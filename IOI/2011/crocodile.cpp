#include "crocodile.h"

#include "bits/stdc++.h"

using namespace std;

struct node {
    int v;
    long long time;

    bool operator<(const node &rhs) const {
        return time > rhs.time;
    }
};

int travel_plan(int n, int m, int R[][2], int L[], int k, int p[]) {
    vector<pair<int, long long>> adj[n + 1];
    for (int i = 0; i < m; i++) {
        int a = R[i][0], b = R[i][1];
        long long c = L[i];
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    vector<int> vis(n + 1, 0);

    priority_queue<node> q;
    for (int i = 0; i < k; i++) {
        q.push({p[i], 0}), vis[p[i]] = 1;
    }

    while (!q.empty()) {
        node v = q.top();
        q.pop();

        vis[v.v]++;
        if (vis[v.v] != 2) continue;

        if (v.v == 0) {
            return v.time;
        }

        for (auto u : adj[v.v]) {
            q.push({u.first, u.second + v.time});
        }
    }
    return -1;
}
