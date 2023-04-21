#include "bits/stdc++.h"
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1, 0), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    vector<int> sum(n + 1, 0);
    for (int i = 1; i <= n; i++) sum[i] = a[i - 1] + sum[i - 1];

    int dp[1 << m];
    memset(dp, 0, sizeof dp);

    for (int i = 0; i < 1 << m; i++) {
        int cursum = 0;
        for (int j = 0; j < m; j++)
            if (i & (1 << j))
                cursum += b[j];
        cursum -= sum[dp[i]];
        for (int j = 0; j < m; j++)
            if (!(i & (1 << j))) {
                if (cursum + b[j] < a[dp[i]])
                    dp[i | (1 << j)] = max(dp[i | (1 << j)], dp[i]);
                if (cursum + b[j] == a[dp[i]])
                    dp[i | (1 << j)] = max(dp[i | (1 << j)], dp[i] + 1);
            }
    }
    for (int i = 0; i < 1 << m; i++)
        if (dp[i] == n) {
            cout << "YES\n";
            return 0;
        }
    cout << "NO\n";
}
