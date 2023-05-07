#include "bits/stdc++.h"
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

template <class T>
using IndSet = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    freopen("mincross.in", "r", stdin);
    freopen("mincross.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    auto solve = [](int n, vector<int> a, vector<int> b) {
        vector<int> ta(n + 1);
        for (int i = 0; i < n; i++)
            ta[a[i]] = i;

        IndSet<int> s;
        long long cur = 0;
        for (int i = 0; i < n; i++) {
            cur += i - s.order_of_key(ta[b[i]]);
            s.insert(ta[b[i]]);
        }

        long long ans = cur;
        for (int i = n - 1; i > 0; i--) {
            cur += ta[b[i]];
            cur -= n - ta[b[i]] - 1;
            ans = min(ans, cur);
        }
        return ans;
    };

    cout << min(solve(n, a, b), solve(n, b, a)) << '\n';
}
