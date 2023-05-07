#include "bits/stdc++.h"
using namespace std;

const int MOD = 1000000007;

int add(int a, int b) { return (a + b) % MOD; }

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; i++)
        cin >> h[i];

    if (n == 1) {
        cout << 0 << '\n';
        return 0;
    }

    int ans = 0;
    for (int a = 0; a <= (n & 1 ? 1000 : 0); a++) {
        int dp[n][1001];
        memset(dp, 0, sizeof dp);

        vector<vector<int>> pref(n);

        pref[1] = vector<int>(h[1] + 1);

        for (int i = 0; i <= min(h[0], h[1]) - a; i++) {
            dp[1][i] = 1;
            pref[1][i] = add((i ? pref[1][i - 1] : 0), 1);
        }
        for (int i = max(min(h[0], h[1]) - a + 1, 0); i <= h[1] - a; i++)
            pref[1][i] = pref[1][i - 1];

        for (int i = 2; i < n; i++) {
            pref[i] = vector<int>(h[i] + 1);
            for (int j = 0; j <= h[i] - a; j++) {
                if (h[i - 1] - j - a < 0)
                    dp[i][j] = 0;
                else
                    dp[i][j] = add(dp[i][j], pref[i - 1][min(h[i - 1] - j - a, (int)size(pref[i - 1]) - 1)]);
                pref[i][j] = add(dp[i][j], (j ? pref[i][j - 1] : 0));
            }
        }

        for (int i = 0; i <= h[n - 1] - a; i++)
            ans = add(ans, dp[n - 1][i]);
    }
    cout << ans << '\n';
}
