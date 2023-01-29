#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> pow(10, 1);
    for (int i = 1; i < 10; i++)
        pow[i] = 9 * pow[i - 1];

    vector<bool> vis(pow[9], false);

    int start = 0;
    for (int i = 0; i < 9; i++) {
        int a;
        cin >> a;
        a--;
        start += a * pow[8 - i];
    }

    int target = 0;
    for (int i = 0; i < 9; i++) {
        target += i * pow[8 - i];
    }

    auto swapping = [&](int k, int a, int b) {
        int na = k % pow[a + 1] / pow[a];
        int nb = k % pow[b + 1] / pow[b];

        return k - na * pow[a] - nb * pow[b] + nb * pow[a] + na * pow[b];
    };

    queue<pair<int, int>> q;
    q.push({start, 0});
    vis[start] = true;
    while (!q.empty()) {
        auto [v, dist] = q.front();
        q.pop();
        if (v == target) {
            cout << dist << '\n';
            break;
        }

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (j + 1 < 3) {
                    int u = swapping(v, (i * 3 + j), (i * 3 + j + 1));
                    if (!vis[u]) {
                        vis[u] = true;
                        q.push({u, dist + 1});
                    }
                }

                if (i + 1 < 3) {
                    int u = swapping(v, (i * 3 + j), ((i + 1) * 3 + j));
                    if (!vis[u]) {
                        vis[u] = true;
                        q.push({u, dist + 1});
                    }
                }
            }
        }
    }
}
