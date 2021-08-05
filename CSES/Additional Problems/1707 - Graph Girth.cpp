#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); 

    int n, m;
    cin >> n >> m;
    vector<int> v[n];
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int ans = 1e9;
    for (int j = 0; j < n; j++) {
        int dist[n]; 
        for (int i = 0; i < n; i++) dist[i] = -1;
        dist[j] = 0;
        queue<int> q;
        q.push(j);
        while (!q.empty()) {
            int k = q.front();
            q.pop();
            for (auto i: v[k]) {
                if (dist[i] == -1) {
                    q.push(i);
                    dist[i] = dist[k]+1;
                } else if (dist[i] >= dist[k]) {
                    ans = min(ans, dist[k]+dist[i]+1);
                }
            }
        }
    }
    if (ans == 1e9) cout << -1 << '\n';
    else cout << ans << '\n';
}

/* Stuff to look for
 * int overflow, array bounds
 * special cases (n=1)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */
