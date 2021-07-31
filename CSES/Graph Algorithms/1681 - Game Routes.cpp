#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); 

    int n, m;
    cin >> n >> m;
    vector<int> v[n];
    int nump[n];
    memset(nump, 0, sizeof(nump));
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        v[a].push_back(b);
        nump[b]++;
    }
    int w[n]; memset(w, 0, sizeof(w));
    queue<int> q;
    for (int i = 0; i < n; i++)
        if (nump[i] == 0) {
            q.push(i);
            w[i] = 0;
        }
    w[0] = 1;
    while (!q.empty()) {
        int k = q.front();
        q.pop();
        for (auto i: v[k]) {
            w[i] += w[k];
            w[i] %= MOD;
            if ((--nump[i]) == 0) {
                q.push(i);
            }
        }
    }
    cout << w[n-1] << '\n';
}

/* Stuff to look for
 * int overflow, array bounds
 * special cases (n=1)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */
