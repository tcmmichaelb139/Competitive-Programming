#include "bits/stdc++.h"
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

template <class T>
using IndTree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    IndTree<pair<int, int>> s;

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        s.insert({v[i], i});
    }

    for (int i = 0; i < q; i++) {
        char c;
        int a, b;
        cin >> c >> a >> b;
        if (c == '!') {
            int ind = (*s.lower_bound({v[a - 1], 0})).second;
            s.erase(s.lower_bound({v[a - 1], 0}));
            s.insert({b, ind});
            v[a - 1] = b;
        } else {
            cout << s.order_of_key({b + 1, 0}) - s.order_of_key({a, 0}) << '\n';
        }
    }
}
