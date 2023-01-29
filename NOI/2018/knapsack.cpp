#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int s, n;
    cin >> s >> n;
    vector<vector<pair<long long, long long>>> v(s + 1);
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (c == 0 || b > s) continue;
        v[b].push_back({a, c});
    }

    long long dp[s + 1];
    for (int i = 0; i <= s; i++)
        dp[i] = -1;
    dp[0] = 0;

    for (int i = 1; i <= s; i++) {
        if (v[i].size() == 0) continue;

        sort(rbegin(v[i]), rend(v[i]));

        for (int j = s; j >= 0; j--) {
            if (dp[j] == -1) continue;

            long long cur = j;
            long long num = 0;
            long long done = 0;
            long long val = 0;
            while (cur + i <= s) {
                if (v[i][num].second == done) num++, done = 0;
                if (num == v[i].size()) break;

                cur += i;

                val += v[i][num].first;
                done++;

                dp[cur] = max(dp[cur], dp[j] + val);
            }
        }
    }

    cout << *max_element(dp, dp + s + 1) << '\n';
}
