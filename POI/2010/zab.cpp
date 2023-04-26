#include "bits/stdc++.h"
using namespace std;

const int MAXN = 1000001;
const int MS = 20;

int n, k;
long long m;
long long p[MAXN];
int jmp[MS][MAXN];
int sz[MAXN];
int vis[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k >> m;
    for (int i = 1; i <= n; i++)
        cin >> p[i];
    pair<int, int> lr = {1, k + 1};
    for (int i = 1; i <= n; i++) {
        while (lr.second < n && p[lr.second + 1] - p[i] < p[i] - p[lr.first])
            lr.first++, lr.second++;
        if (p[i] - p[lr.first] >= p[lr.second] - p[i])
            jmp[0][i] = lr.first;
        else
            jmp[0][i] = lr.second;
    }

    for (int i = 1; i < MS; i++)
        for (int j = 1; j <= n; j++)
            jmp[i][j] = jmp[i - 1][jmp[i - 1][j]];

    for (int i = 1; i <= n; i++) {
        int j = i;
        for (; vis[j] == 0; j = jmp[0][j])
            vis[j] = i;
        if (vis[j] != i) continue;
        int cur = 0;
        for (; vis[j] == i; j = jmp[0][j])
            cur++, vis[j] += n;
        for (; vis[j] == i + n; j = jmp[0][j])
            sz[j] = cur, vis[j] += n;
    }

    auto get = [&](int a, int num) {
        for (int j = 0; j < MS; j++)
            if (num & (1ll << j))
                a = jmp[j][a];
        return a;
    };

    for (int i = 1; i <= n; i++) {
        if (m <= n)
            cout << get(i, m) << " \n"[i == n];
        else {
            int cur = get(i, n);
            cout << get(cur, (m - n) % sz[cur]) << " \n"[i == n];
        }
    }
}
