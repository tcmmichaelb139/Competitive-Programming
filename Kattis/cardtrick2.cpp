#include "bits/stdc++.h"
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    int cur = 0;
    queue<int> q;
    for (int i = 0; i < n; i++)
        q.push(i);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            q.push(q.front());
            q.pop();
        }
        v[q.front()] = i;
        q.pop();
    }
    for (int i = 0; i < n; i++)
        cout << v[i] << " \n"[i + 1 == n];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}
