#include "bits/stdc++.h"
using namespace std;

const int MAXN = 200001, MS = 20;

int n, q;
int parent[MAXN];
vector<int> adj[MAXN];
int jmp[MS][MAXN];
int group[MAXN];
int loopSize[MAXN];
int loopDepth[MAXN];
int depth[MAXN];
int root[MAXN];

int numPar[MAXN];
bool visRB[MAXN];
bool visG[MAXN];
bool visD[MAXN];

void removeBranches(int v) {
    visRB[v] = true;
    if (--numPar[parent[v]] == 0)
        removeBranches(parent[v]);
}

void findGroups(int v, int g) {
    visG[v] = true;
    group[v] = g;
    for (auto u : adj[v]) {
        if (visG[u]) continue;
        visG[u] = true;
        findGroups(u, g);
    }
}

void findLoop(int v, int s) {
    loopSize[group[v]]++;
    if (parent[v] != s) {
        loopDepth[parent[v]] = loopDepth[v] + 1;
        findLoop(parent[v], s);
    }
}

void findDepth(int v, int r) {
    visD[v] = true;
    root[v] = r;
    for (auto u : adj[v]) {
        if (visD[u] || !visRB[u]) continue;
        visD[u] = true;
        depth[u] = depth[v] + 1;
        findDepth(u, r);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        parent[i] = a;
        jmp[0][i] = a;
        adj[a].push_back(i);
        adj[i].push_back(a);

        numPar[a]++;
    }

    for (int i = 1; i < MS; i++)
        for (int j = 1; j <= n; j++)
            jmp[i][j] = jmp[i - 1][jmp[i - 1][j]];

    for (int i = 1; i <= n; i++)
        if (!visRB[i] && numPar[i] == 0)
            removeBranches(i);

    for (int i = 1; i <= n; i++)
        if (!visG[i])
            findGroups(i, i);

    for (int i = 1; i <= n; i++)
        if (!loopSize[group[i]] && !visRB[i])
            findLoop(i, i);

    for (int i = 1; i <= n; i++)
        if (!visRB[i])
            findDepth(i, i);

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;

        if (group[a] != group[b]) {
            cout << -1 << '\n';
        } else if (!visRB[a] && !visRB[b]) {
            cout << loopDepth[b] - loopDepth[a] + (loopDepth[b] < loopDepth[a] ? loopSize[group[a]] : 0) << '\n';
        } else if (visRB[a] && !visRB[b]) {
            cout << depth[a] + loopDepth[b] - loopDepth[root[a]] + (loopDepth[b] < loopDepth[root[a]] ? loopSize[group[a]] : 0) << '\n';
        } else if (visRB[a] && visRB[b]) {
            int num = depth[a] - depth[b];
            for (int j = 0; j < MS; j++)
                if (num & (1 << j))
                    a = jmp[j][a];
            if (a == b)
                cout << num << '\n';
            else
                cout << -1 << '\n';
        } else {
            cout << -1 << '\n';
        }
    }
}
