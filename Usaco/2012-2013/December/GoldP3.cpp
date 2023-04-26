#include "bits/stdc++.h"
using namespace std;

const int MAXN = 200001, MS = 20;

int n;
long long l;
vector<int> adj[MAXN];
int jmp[MS][MAXN];
long long len[MS][MAXN];

int e[MAXN];
int ans[MAXN];

int dfs(int v) {
    int cur = 1;
    for (auto u : adj[v])
        cur += dfs(u);

    ans[v] = cur;
    cur -= e[v];

    return cur;
}

int main() {
    freopen("runaway.in", "r", stdin);
    freopen("runaway.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> l;
    for (int i = 2; i <= n; i++) {
        int a;
        long long b;
        cin >> a >> b;
        adj[a].push_back(i);
        jmp[0][i] = a;
        len[0][i] = b;
    }

    for (int i = 1; i < MS; i++)
        for (int j = 1; j <= n; j++) {
            jmp[i][j] = jmp[i - 1][jmp[i - 1][j]];
            len[i][j] = len[i - 1][j] + len[i - 1][jmp[i - 1][j]];
        }

    for (int i = 1; i <= n; i++) {
        int cur = i;
        long long curSum = l;
        for (int j = MS - 1; j >= 0; j--) {
            if (curSum >= len[j][cur]) {
                curSum -= len[j][cur];
                cur = jmp[j][cur];
            }
        }

        e[cur]++;
    }

    dfs(1);

    for (int i = 1; i <= n; i++)
        cout << ans[i] << '\n';
}
