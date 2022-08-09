#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    vector<int> v(n), ind(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        v[i]--;
        ind[v[i]] = i;
    }
    int ans = 1;
    for (int i = 1; i < n; i++)
        if (ind[i] < ind[i - 1]) ans++;

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;

        int va = v[a], vb = v[b];
        if (va > vb) swap(va, vb);

        if (va > 0) {
            if (ind[va - 1] < ind[va] && ind[va - 1] > ind[vb])
                ans++;
            else if (ind[va - 1] > ind[va] && ind[va - 1] < ind[vb])
                ans--;
        }
        if (vb < n - 1) {
            if (ind[vb + 1] > ind[vb] && ind[vb + 1] < ind[va])
                ans++;
            else if (ind[vb + 1] < ind[vb] && ind[vb + 1] > ind[va])
                ans--;
        }
        if (abs(va - vb) == 1) {
            if (ind[vb] > ind[va])
                ans++;
            else
                ans--;
        } else {
            if (ind[va + 1] > ind[va] && ind[va + 1] < ind[vb])
                ans++;
            else if (ind[va + 1] < ind[va] && ind[va + 1] > ind[vb])
                ans--;

            if (ind[vb - 1] < ind[vb] && ind[vb - 1] > ind[va])
                ans++;
            else if (ind[vb - 1] > ind[vb] && ind[vb - 1] < ind[va])
                ans--;
        }
        swap(ind[va], ind[vb]);
        swap(v[a], v[b]);
        cout << ans << '\n';
    }
}
