#include "bits/stdc++.h"
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, mn, mx;
    cin >> n >> mn >> mx;
    vector<long long> v(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> v[i];

    vector<long long> pref(n + 1, 0);
    for (int i = 1; i <= n; i++)
        pref[i] = pref[i - 1] + v[i];

    multiset<long long> m;

    long long ans = -1e18;
    for (int i = mn; i <= n; i++) {
        if (i > mx)
            m.erase(m.find(pref[i - mx - 1]));

        m.insert(pref[i - mn]);

        ans = max(ans, pref[i] - *begin(m));
    }
    cout << ans << '\n';
}
