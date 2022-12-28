#include "bits/stdc++.h"
using namespace std;

const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

int n;
int tmpx = 1, tmpy = 1;
set<pair<int, int>> ar;
set<pair<int, int>> vis;
int ans = 0;

bool alone(int x, int y) {
    for (int i = -1; i <= 1; i++)
        for (int j = -1; j <= 1; j++)
            if (ar.count({x + i, y + j})) return false;
    return true;
}

void ff(int x, int y) {
    if (ar.count({x, y})) {
        ans++;
        return;
    }
    if (vis.count({x, y})) return;
    vis.insert({x, y});
    if (alone(x, y)) return;

    for (int i = 0; i < 4; i++)
        ff(x + dx[i], y + dy[i]);
}

int main() {
    freopen("perimeter.in", "r", stdin);
    freopen("perimeter.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        ar.insert({a, b});
    }

    pair<int, int> start = *begin(ar);

    ff(start.first - 1, start.second);

    cout << ans << '\n';
}
