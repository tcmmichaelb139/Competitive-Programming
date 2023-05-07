#include "bits/stdc++.h"
using namespace std;

const int MX = 1000000, MAXN = 5000;
long long dp[MAXN][MAXN];
long long num[MX * 2 + 1];

int main() {
    freopen("threesum.in", "r", stdin);
    freopen("threesum.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    for (int l = 0; l < n; l++) {
        num[v[l + 1] + MX]++;
        for (int r = l + 2; r < n; r++) {
            if (abs(v[l] + v[r]) <= MX)
                dp[l][r] = num[-(v[l] + v[r]) + MX];
            num[v[r] + MX]++;
        }
        for (int r = l + 1; r < n; r++)
            num[v[r] + MX]--;
    }

    for (int len = 2; len < n; len++) {
        for (int l = 0; l < n - len; l++) {
            int r = l + len;
            dp[l][r] += dp[l + 1][r] + dp[l][r - 1] - dp[l + 1][r - 1];
        }
    }

    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << dp[a - 1][b - 1] << '\n';
    }
}
