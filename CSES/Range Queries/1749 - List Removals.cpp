#include "bits/stdc++.h"
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

template <class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> v(n);
    Tree<int> s;

    for (int i = 0; i < n; i++)
        cin >> v[i], s.insert(i);

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        a--;
        cout << v[*s.find_by_order(a)] << " \n"[i + 1 == n];
        s.erase(*s.find_by_order(a));
    }
}
