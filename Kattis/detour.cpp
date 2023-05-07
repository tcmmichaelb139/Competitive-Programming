#include "bits/stdc++.h"
using namespace std;

struct Node {
    int v;
    int p;
    int d;

    bool operator<(const Node &rhs) const {
        return d > rhs.d;
    }
};

const int MAXN = 100001;

int n, m;
vector<pair<int, int>> adj[MAXN];
bool vis[MAXN];
int dir[MAXN];
int pre[MAXN];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    auto findDir = [&]() {
        priority_queue<Node> q;
        q.push({1, -1, 0});

        while (!q.empty()) {
            Node v = q.top();
            q.pop();

            if (vis[v.v]) continue;
            vis[v.v] = true;

            dir[v.v] = v.p;

            for (auto u : adj[v.v]) {
                if (vis[u.first]) continue;
                q.push({u.first, v.v, v.d + u.second});
            }
        }
    };

    auto findPath = [&]() {
        queue<int> q;
        q.push(0);

        while (!q.empty()) {
            int v = q.front();
            q.pop();

            vis[v] = true;

            for (auto u : adj[v]) {
                if (u.first == dir[v]) continue;
                if (vis[u.first]) continue;
                vis[u.first] = true;
                pre[u.first] = v;
                q.push(u.first);
            }
        }
    };

    for (int i = 0; i < n; i++)
        dir[i] = pre[i] = -1;
    findDir();
    memset(vis, false, sizeof vis);
    findPath();

    if (pre[1] == -1) {
        cout << "impossible\n";
    } else {
        vector<int> path;
        for (int i = 1; i != -1; i = pre[i])
            path.push_back(i);

        reverse(begin(path), end(path));

        cout << size(path) << ' ';
        for (int i = 0; i < size(path); i++)
            cout << path[i] << " \n"[i + 1 == size(path)];
    }
}
