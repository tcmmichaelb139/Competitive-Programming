#include "bits/stdc++.h"
using namespace std;

const int mx = 2e6;

vector<int> dp_calc(vector<int> v, int n) {
    vector<int> dp(mx, 1e9);
    dp[0] = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < mx; j++)
            if (j + v[i] < mx)
                dp[j + v[i]] = min(dp[j + v[i]], dp[j] + 1);
    return dp;
}

vector<int> greedy_calc(vector<int> v, int n) {
    vector<int> greedy(mx, 1e9);
    greedy[0] = 0;
    for (int j = 1; j < mx; j++) {
        auto it = lower_bound(begin(v), end(v), j);
        if (it == begin(v) && *it != j) {
            greedy[j] = -1e9;
        } else if (it == end(v) || *it != j) {
            it--;
            greedy[j] = greedy[j - *it] + 1;
        } else {
            greedy[j] = 1;
        }
    }
    return greedy;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    vector<int> dp = dp_calc(v, n);
    vector<int> greedy = greedy_calc(v, n);

    for (int i = 0; i < mx; i++)
        if (dp[i] != greedy[i]) {
            cout << "non-canonical\n";
            return 0;
        }
    cout << "canonical\n";
}
