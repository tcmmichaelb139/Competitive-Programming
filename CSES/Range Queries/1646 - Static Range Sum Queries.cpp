#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    vector<long long> v(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        long long a;
        cin >> a;
        v[i] = v[i - 1] + a;
    }
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        cout << v[b] - v[a - 1] << '\n';
    }
}
