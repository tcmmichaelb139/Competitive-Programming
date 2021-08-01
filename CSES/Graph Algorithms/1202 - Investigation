#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); 

    int n, m;
    cin >> n >> m;
    vector<pair<long long, int>> v[n];
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        a--, b--;
        v[a].push_back({w, b});
    }
    bool vis[n]; memset(vis, false, sizeof(vis));
    long long dist[n]; memset(dist, 100, sizeof(dist));
    dist[0] = 0;
    long long nmn[n]; memset(nmn, 0, sizeof(nmn));
    nmn[0] = 1;
    long long mnf[n]; memset(mnf, 100, sizeof(mnf));
    mnf[0] = 0;
    long long mxf[n]; memset(mxf, 0, sizeof(mxf));
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;
    q.push({0, 0});
    while (!q.empty()) {
        pair<long long, int> k = q.top();
        q.pop();
        if (vis[k.second]) continue;
        vis[k.second] = true;
        for (auto i: v[k.second]) {
            if (i.first+k.first == dist[i.second]) {
                nmn[i.second] += nmn[k.second];
                nmn[i.second] %= MOD;
                mnf[i.second] = min(mnf[i.second], mnf[k.second]+1);
                mxf[i.second] = max(mxf[i.second], mxf[k.second]+1);
            } else if (i.first+k.first < dist[i.second]) {
                dist[i.second] = i.first+dist[k.second];
                nmn[i.second] = nmn[k.second];
                mnf[i.second] = mnf[k.second]+1;
                mxf[i.second] = mxf[k.second]+1;
                q.push({i.first+k.first, i.second});
            }
        }
    }
    cout << dist[n-1] << ' ' << nmn[n-1] << ' ' << mnf[n-1] << ' ' << mxf[n-1] << '\n';
}

/* Stuff to look for
 * int overflow, array bounds
 * special cases (n=1)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */
