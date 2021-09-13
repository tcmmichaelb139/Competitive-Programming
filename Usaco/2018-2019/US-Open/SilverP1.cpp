#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); 
    freopen("leftout.in","r",stdin);
    freopen("leftout.out","w",stdout);

    int n;
    cin >> n;
    bool v[n][n];
    int l = 0, r = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            if (s[j] == 'R') {
                v[i][j] = true;
                r++;
            }
            else {
                v[i][j] = false;
                l++;
            }
        }
    }
    while (true) {
        int c = 0;
        for (int i = 0; i < n; i++) {
            int le = 0, hi = 0;
            for (int j = 0; j < n; j++) {
                if (v[i][j]) hi++;
                else le++;
            }
            if (le < hi) {
                for (int j = 0; j < n; j++)
                    v[i][j] = !v[i][j];
                c++;
            }
        }
        for (int i = 0; i < n; i++) {
            int le = 0, hi = 0;
            for (int j = 0; j < n; j++) {
                if (v[j][i]) hi++;
                else le++;
            }
            if (le < hi) {
                for (int j = 0; j < n; j++)
                    v[j][i] = !v[j][i];
                c++;
            }
        }
        if (c == 0) break;
    }
    int k = 0;
    int ans1, ans2;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) 
            if (v[i][j]) {
                ans1 = i+1;
                ans2 = j+1;
                k++;
            }
    }
    if (k > 1 || k == 0) cout << -1 << '\n';
    else cout << ans1 << ' ' << ans2 << '\n';
}

/* Stuff to look for
 * int overflow, array bounds
 * special cases (n=1)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */
