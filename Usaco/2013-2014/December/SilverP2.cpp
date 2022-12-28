#include "bits/stdc++.h"
using namespace std;

struct node {
    long long v;
    long long dist;
    bool gth;
    bool operator<(const node& rhs) const {
        return dist > rhs.dist;
    }
};

const long long MAXN = 201;

long long N, M, K, Q;
long long dist[MAXN][MAXN][2];
bool vis[MAXN][2];
vector<pair<long long, long long>> adj[MAXN];

void dijkstra(long long start) {
    memset(vis, false, sizeof vis);
    priority_queue<node> q;
    q.push({start, 0, (start < K)});
    while (!q.empty()) {
        node v = q.top();
        q.pop();
        if (vis[v.v][v.gth]) continue;
        vis[v.v][v.gth] = true;
        dist[start][v.v][v.gth] = v.dist;

        for (auto u : adj[v.v]) {
            q.push({u.first, v.dist + u.second, (bool)(v.gth | (u.first < K))});
        }
    }
}

int main() {
    freopen("vacation.in", "r", stdin);
    freopen("vacation.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K >> Q;
    for (int i = 0; i < M; i++) {
        long long a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        adj[a].push_back({b, c});
    }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            dist[i][j][0] = dist[i][j][1] = -1;

    for (int i = 0; i < N; i++)
        dijkstra(i);

    int num = 0;
    long long ans = 0;
    for (int i = 0; i < Q; i++) {
        int a, b;
        cin >> a >> b;
        if (dist[--a][--b][1] != -1)
            ans += dist[a][b][1], num++;
    }
    cout << num << '\n'
         << ans << '\n';
}
