#include "bits/stdc++.h"
using namespace std;

const int MAXN = 1001;

vector<int> adj[MAXN];

int par[MAXN];

set<int> pos[MAXN];
bool pos1[MAXN], pos2[MAXN];

void topo(int v) {
    for (auto u : adj[v]) {
        for (auto i : pos[v])
            pos[u].insert(i + 1);
        if (--par[u] == 0)
            topo(u);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n1, n2, m1, m2;
    cin >> n1 >> n2 >> m1 >> m2;
    for (int i = 0; i < m1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        par[b]++;
    }

    pos[1].insert(0);
    topo(1);
    for (auto i : pos[n1])
        pos1[i] = true;

    memset(par, 0, sizeof par);
    for (int i = 0; i < MAXN; i++)
        adj[i].clear(), pos[i].clear();

    for (int i = 0; i < m2; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        par[b]++;
    }

    pos[1].insert(0);
    topo(1);
    for (auto i : pos[n2])
        pos2[i] = true;

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int a;
        cin >> a;
        bool yes = false;
        for (int j = 0; j <= n1; j++) {
            if (pos1[j])
                if (a - j <= n2 && a - j >= 0)
                    if (pos2[a - j]) {
                        yes = true;
                        break;
                    }
        }
        if (yes)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}
