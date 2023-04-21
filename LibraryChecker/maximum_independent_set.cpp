#include "bits/stdc++.h"
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<bool>> v(n, vector<bool>(n, false));
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        v[a][b] = v[b][a] = true;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    auto indep = [&](long long i, int add) {
        for (int a = 0; a < 21; a++)
            if (i & (1 << a))
                for (int b = a + 1; b < 21; b++)
                    if (i & (1 << b) && v[a + add][b + add])
                        return false;
        return true;
    };

    vector<long long> best(1 << n / 2, 0);
    for (long long i = 0; i < 1 << n / 2; i++) {
        if (!indep(i, 0)) {
            for (int j = 0; j <= n / 2; j++)
                if (i & (1 << j))
                    if (__builtin_popcountll(best[i]) < __builtin_popcountll(best[i ^ (1 << j)]))
                        best[i] = best[i ^ (1 << j)];
        } else
            best[i] = i;
    }
    long long ans = 0;
    for (long long i = 0; i < 1 << (n + 1) / 2; i++) {
        if (!indep(i, n / 2)) continue;

        long long val = (1 << n / 2) - 1;
        for (int j = 0; j <= (n + 1) / 2; j++)
            if (i & (1 << j))
                for (auto a : adj[j + n / 2])
                    if (a < n / 2)
                        val &= ~(1 << a);
        if (__builtin_popcountll(ans) < __builtin_popcountll(best[val]) + __builtin_popcountll(i))
            ans = best[val] + (i << n / 2);
    }
    vector<long long> sol;
    for (long long i = 0; i < n; i++)
        if (ans & (1ll << i))
            sol.push_back(i);
    cout << sol.size() << '\n';
    for (int i = 0; i < sol.size(); i++)
        cout << sol[i] << " \n"[i + 1 == sol.size()];
}
