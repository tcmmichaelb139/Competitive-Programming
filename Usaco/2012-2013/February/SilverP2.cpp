#include<bits/stdc++.h>
using namespace std;

struct DSU {
    pair<int, int> v[501][501];
    void init() {
        for (int i = 0; i <= 500; i++) 
            for (int j = 0; j <= 500; j++) 
                v[i][j] = {-1, -1}; }
    pair<int, int> get(pair<int, int> a) { 
        return (v[a.first][a.second].first < 0 ? a : get(v[a.first][a.second])); }
    int size(pair<int, int> a) { return -v[get(a).first][get(a).second].first; }
    bool unite(pair<int, int> a, pair<int, int> b) {
        a = get(a), b = get(b);
        if (a == b) return false;
        if (v[a.first][a.second].first > v[b.first][b.second].first) swap(a, b);
        v[a.first][a.second].first += v[b.first][b.second].first;
        v[b.first][b.second] = a;
        return true;
    }
};

int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

int main() {
    freopen("tractor.in", "r", stdin);
    freopen("tractor.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);

    int n; cin >> n;
    int ar[n+1][n+1];
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) 
            cin >> ar[i][j];
    int l = 0, r = 1e7;
    while (l < r) {
        int mid = l+(r-l)/2;
        DSU dsu;
        dsu.init();
        int mx = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int a = 0; a < 4; a++) {
                    if (i+dx[a] < 0 || i+dx[a] >= n || j+dy[a] < 0 || j+dy[a] >= n) continue;
                    if (abs(ar[i][j]-ar[i+dx[a]][j+dy[a]]) <= mid) {
                        dsu.unite({i, j}, {i+dx[a], j+dy[a]});
                        mx = max(mx, dsu.size({i, j}));
                    }
                }
            }
        }
        if (mx >= (n*n+1)/2) {
            r = mid;
        } else {
            l = mid+1;
        }
    }
    cout << r << '\n';
}
