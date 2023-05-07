#include "bits/stdc++.h"
using namespace std;

int main() {
    freopen("berries.in", "r", stdin);
    freopen("berries.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    int ans = 0;
    for (int i = 1; i < 1000; i++) {
        int all = 0;
        for (int j = 0; j < n; j++)
            all += v[j] / i;
        if (all < k / 2) break;
        if (all >= k) {
            ans = max(ans, (k / 2) * i);
            continue;
        }

        vector<int> pos;
        for (int j = 0; j < n; j++)
            pos.push_back(v[j] % i);
        sort(rbegin(pos), rend(pos));
        int left = 0;
        for (int j = 0; j < k - all && j < n; j++)
            left += pos[j];
        ans = max(ans, (all - k / 2) * i + left);
    }
    cout << ans << '\n';
}
