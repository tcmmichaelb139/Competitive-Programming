#include "bits/stdc++.h"
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    long long ans = 0;

    map<int, long long> cur;
    set<int> s;
    long long total = 0;
    int l = 0;
    for (int r = 0; r < n; r++) {
        cur[v[r]]++;
        total++;
        s.insert(v[r]);
        while (s.size() > m) {
            cur[v[l]]--;
            if (cur[v[l]] == 0)
                s.erase(v[l]);
            l++;
            total--;
        }
        ans += total;
    }
    cout << ans << '\n';
}
