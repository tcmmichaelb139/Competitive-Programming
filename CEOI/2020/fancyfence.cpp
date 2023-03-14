#include "bits/stdc++.h"
using namespace std;

const long long MOD = 1e9 + 7;
long long add(long long a, long long b) { return ((a + b + MOD) % MOD) + MOD % MOD; }
long long mult(long long a, long long b) { return a * b % MOD; }
long long numRec(long long a, long long b) { return mult(mult(mult(a, b), mult(a + 1, b + 1)), 250000002); }

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<long long> h(n), w(n);
    for (int i = 0; i < n; i++)
        cin >> h[i];
    for (int i = 0; i < n; i++)
        cin >> w[i];

    vector<long long> l(n), r(n);
    stack<pair<long long, long long>> s;
    long long cur = 0;
    s.push({-1, 0});
    for (int i = 0; i < n; i++) {
        while (!s.empty() && s.top().first > h[i])
            s.pop();

        l[i] = s.top().second;

        cur += w[i];
        s.push({h[i], cur});
    }
    while (!s.empty()) s.pop();
    s.push({-1, cur});
    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && s.top().first >= h[i])
            s.pop();

        r[i] = s.top().second;

        cur -= w[i];
        s.push({h[i], cur});
    }

    long long ans = 0;
    cur = 0;
    for (int i = 0; i < n; i++) {
        ans = add(ans, add(add(numRec(add(r[i], -l[i]), h[i]), -numRec(add(cur, -l[i]), h[i])), -numRec(add(add(r[i], -w[i]), -cur), h[i])));
        cur += w[i];
    }
    cout << ans << '\n';
}
