#include "bits/stdc++.h"
using namespace std;

struct DSU {
    vector<int> v;
    void init(int n) { v.assign(n, -1); }
    int get(int p) { return v[p] < 0 ? p : v[p] = get(v[p]); }
    bool unite(int a, int b) {
        a = get(a), b = get(b);
        if (a == b) return false;
        // if (v[a] > v[b]) swap(a, b);
        v[a] += v[b];
        v[b] = a;
        return true;
    }
};

int dx[] = {-1, 0, 0, 1}, dy[] = {0, -1, 1, 0};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    map<int, pair<int, int>> ind;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
            ind[i + j * n] = {i, j};
        }

    DSU dsu;
    dsu.init(n * m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int mn = 1e9;
            for (int a = 0; a < 4; a++) {
                int x = i + dx[a], y = j + dy[a];
                if (x < 0 || y < 0 || x >= n || y >= m) continue;

                mn = min(mn, v[x][y]);
            }

            if (mn >= v[i][j]) continue;

            for (int a = 0; a < 4; a++) {
                int x = i + dx[a], y = j + dy[a];
                if (x < 0 || y < 0 || x >= n || y >= m) continue;

                if (mn == v[x][y]) {
                    dsu.unite(i + j * n, x + y * n);
                    break;
                }
            }
        }
    }

    map<int, char> conv;
    int num = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (conv.find(dsu.get(i + j * n)) == conv.end())
                conv[dsu.get(i + j * n)] = (char)('a' + num++);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cout << conv[dsu.get(i + j * n)] << " \n"[j + 1 == m];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ":\n";
        solve();
    }
}
