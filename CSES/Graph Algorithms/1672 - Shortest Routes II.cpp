#include "bits/stdc++.h"
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n, m, q;
    cin >> n >> m >> q;
    long long d[n + 1][n + 1];
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            d[i][j] = (i == j ? 0 : 1e18);

    for (int i = 0; i < m; i++) {
        long long a, b, c;
        cin >> a >> b >> c;
        d[a][b] = min(d[a][b], c);
        d[b][a] = min(d[b][a], c);
    }

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        if (d[a][b] == (long long)(1e18))
            cout << -1 << '\n';
        else
            cout << d[a][b] << '\n';
    }
}
