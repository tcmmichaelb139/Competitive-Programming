#include "bits/stdc++.h"
using namespace std;

const int MAXN = 250, MAXW = 1001;

int N, W;
long long dp[MAXW];
long long t[MAXN], w[MAXN];

bool check(int k) {
    for (int i = 0; i <= W; i++)
        dp[i] = -1e18;
    dp[0] = 0;
    for (int i = 0; i < N; i++) {
        for (int j = W; j >= 0; j--) {
            if (dp[j] == (int)-1e18) continue;
            int mn = min(W, j + (int)w[i]);
            dp[mn] = max(dp[mn], dp[j] + 1000 * t[i] - k * w[i]);
        }
    }
    return dp[W] >= 0;
}

int main() {
    freopen("talent.in", "r", stdin);
    freopen("talent.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> W;
    for (int i = 0; i < N; i++)
        cin >> w[i] >> t[i];

    int l = 0, r = 1e9;
    while (l < r) {
        int mid = l + (r - l + 1) / 2;
        if (check(mid))
            l = mid;
        else
            r = mid - 1;
    }
    cout << l << '\n';
}
