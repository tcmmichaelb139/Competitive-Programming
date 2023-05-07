#include "bits/stdc++.h"
using namespace std;

const int MAXN = 100001;

int n;
int par[MAXN], numPar[MAXN];
bool vis[MAXN];

void dfs(int v) {
    vis[v] = true;
    if (--numPar[par[v]] == 0)
        dfs(par[v]);
}

int main() {
    freopen("shuffle.in", "r", stdin);
    freopen("shuffle.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;

        par[i] = a;
        numPar[a]++;
    }

    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        if (numPar[i]) continue;
        dfs(i);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (numPar[i])
            ans++;
    cout << ans << '\n';
}
