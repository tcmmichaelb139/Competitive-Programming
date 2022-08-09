#include "bits/stdc++.h"
using namespace std;

const int MAXN = 1e5 + 1;

vector<int> dp_calc(vector<int> v, int n) {
    vector<int> dp(MAXN, 1e9);
    dp[0] = 0;
    for (int i = 0; i < n; i++)
        for (int j = MAXN - 1; j >= 0; j--)
            if (j + v[i] < MAXN)
                dp[j + v[i]] = min(dp[j + v[i]], dp[j] + 1);
    return dp;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int H;
    cin >> H;
    vector<int> h(H);
    for (int i = 0; i < H; i++)
        cin >> h[i];

    int B;
    cin >> B;
    vector<int> b(B);
    for (int i = 0; i < B; i++)
        cin >> b[i];

    vector<int> dp1 = dp_calc(h, H);
    vector<int> dp2 = dp_calc(b, B);

    int ans = 1e9;
    for (int i = 1; i < MAXN; i++) {
        if (dp1[i] == 1e9 || dp2[i] == 1e9) continue;
        ans = min(ans, dp1[i] + dp2[i]);
    }
    if (ans == 1e9)
        cout << "impossible\n";
    else
        cout << ans << '\n';
}
