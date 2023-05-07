#include "bits/stdc++.h"
using namespace std;

const int MAXN = 100001;

int n;
vector<int> adj[MAXN];
vector<int> divs;
int dp[MAXN];
int cur = 0;
bool done = false;

void findDivs() {
    for (int i = 1; i <= n / 2; i++) {
        if ((n - 1) % i == 0)
            divs.push_back(i);
    }
}

void dfs(int v, int p) {
    map<int, int> lens;
    for (auto u : adj[v]) {
        if (u == p) continue;
        dfs(u, v);
        if (done) return;
        if (dp[u] + 1 == cur) continue;
        lens[dp[u] + 1]++;
    }

    if (size(lens)) {
        int left = 0, len = 0;
        for (auto u : lens) {
            if (lens.find(cur - u.first) != lens.end()) {
                if (cur - u.first == u.first)
                    lens[u.first] = lens[u.first] & 1;
                else {
                    int mn = min(lens[cur - u.first], lens[u.first]);
                    lens[cur - u.first] -= mn;
                    lens[u.first] -= mn;
                }
            }
            if (lens[u.first] != 0) {
                left += lens[u.first];
                len = u.first;
                if (left >= 2) {
                    done = true;
                    return;
                }
            }
        }
        if (left == 0)
            dp[v] = 0;
        else if (left == 1)
            dp[v] = len;
    } else {
        dp[v] = 0;
    }
}

int main() {
    freopen("deleg.in", "r", stdin);
    freopen("deleg.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    findDivs();

    vector<bool> ans(n, false);
    vector<bool> no(n, true);

    for (int i = 0; i < size(divs); i++) {
        if (!no[divs[i]]) continue;
        memset(dp, 0, sizeof dp);
        done = false;
        cur = divs[i];
        dfs(1, 0);
        if (dp[1] == 0 && !done)
            ans[cur] = true;
        else
            for (int j = cur; j < n; j += cur)
                no[j] = false;
    }

    for (int i = 1; i < n; i++)
        cout << ans[i];
    cout << '\n';
}
