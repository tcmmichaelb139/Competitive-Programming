#include "bits/stdc++.h"
using namespace std;

struct Node {
    long long h, w, s;
};

int main() {
    freopen("guard.in", "r", stdin);
    freopen("guard.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, h;
    cin >> n >> h;
    vector<Node> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i].h >> v[i].w >> v[i].s;

    long long dp[1 << n];
    for (int i = 0; i < 1 << n; i++)
        dp[i] = -1e9;

    for (int i = 0; i < n; i++)
        dp[1 << i] = v[i].s;

    for (int i = 0; i < 1 << n; i++) {
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) continue;
            if (dp[i] - v[j].w < 0) continue;

            dp[i | (1 << j)] = max(dp[i | (1 << j)], min(dp[i] - v[j].w, v[j].s));
        }
    }

    long long ans = -1;
    for (int i = 0; i < 1 << n; i++) {
        long long sum = 0;
        for (int j = 0; j < n; j++)
            if (i & (1 << j))
                sum += v[j].h;
        if (sum >= h)
            ans = max(ans, dp[i]);
    }
    if (ans == -1)
        cout << "Mark is too tall\n";
    else
        cout << ans << '\n';
}
