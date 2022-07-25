#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    while (cin >> n) {
        if (n == 0) break;

        vector<int> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        v.push_back(1e9);

        int pre[n + 1];
        memset(pre, -1, sizeof pre);
        int dp[n + 1];
        for (int i = 0; i <= n; i++)
            dp[i] = 1;
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j < i; j++)
                if (v[i] > v[j]) {
                    if (dp[i] < dp[j] + 1) {
                        dp[i] = dp[j] + 1;
                        pre[i] = j;
                    } else if (dp[i] == dp[j] + 1)
                        if (v[pre[i]] > v[j])
                            pre[i] = j;
                }
        }

        vector<int> ans;
        for (int i = pre[n]; i != -1; i = pre[i])
            ans.push_back(v[i]);

        reverse(begin(ans), end(ans));

        cout << ans.size() << ' ';
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " \n"[i + 1 == ans.size()];
    }
}
