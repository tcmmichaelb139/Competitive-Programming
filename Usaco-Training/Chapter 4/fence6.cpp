/*
ID: tcmmich1
TASK: fence6
LANG: C++
 */
#include "bits/stdc++.h"
using namespace std;

struct Node {
    int v;
    int dist;
    bool en;

    bool operator<(const Node &rhs) const {
        return dist > rhs.dist;
    }
};

const int MAXN = 101;

int len[MAXN];
vector<int> con[MAXN][2];  // 0 -> begin 1 -> end
bool vis[MAXN];

int dijkstra(int start) {
    int best = 1e9;

    memset(vis, false, sizeof vis);

    priority_queue<Node> q;
    q.push({start, len[start], 1});

    while (!q.empty()) {
        Node v = q.top();
        q.pop();

        if (vis[v.v]) continue;
        vis[v.v] = true;

        for (auto u : con[v.v][v.en]) {
            if (start == u) {
                for (auto i : con[start][0])
                    if (i == v.v)
                        best = min(best, v.dist);
            } else {
                bool beg = false;
                for (auto i : con[u][0])
                    if (i == v.v)
                        beg = true;
                q.push({u, v.dist + len[u], beg});
            }
        }
    }

    return best;
}

int main() {
    freopen("fence6.in", "r", stdin);
    freopen("fence6.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int s, l, n1, n2;
        cin >> s >> l >> n1 >> n2;

        len[s] = l;

        for (int j = 0; j < n1; j++) {
            int a;
            cin >> a;
            con[s][0].push_back(a);
        }
        for (int j = 0; j < n2; j++) {
            int a;
            cin >> a;
            con[s][1].push_back(a);
        }
    }

    int ans = 1e9;
    for (int i = 1; i <= n; i++) {
        ans = min(ans, dijkstra(i));
    }
    cout << ans << '\n';
}
