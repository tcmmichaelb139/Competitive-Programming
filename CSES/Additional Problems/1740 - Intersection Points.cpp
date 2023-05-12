#include "bits/stdc++.h"
using namespace std;

template <class T>
struct BIT {
    vector<T> v;
    int n;
    void init(int _n) {
        n = _n;
        v.resize(n + 1);
    }
    void add(int p, T val) {
        for (; p <= n; p += p & -p) v[p] += val;
    }
    T sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
    T sum(int k) {
        T sum = 0;
        for (; k; k -= k & -k) sum += v[k];
        return sum;
    }
};

const int MAXXY = 1e6 + 1;

set<int> vals;
vector<pair<int, int>> vert[2 * MAXXY + 1];
vector<int> hor[2 * MAXXY + 1];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a += MAXXY, b += MAXXY, c += MAXXY, d += MAXXY;
        if (a == c) {
            vert[a].push_back({b, d});
            vals.insert(a);
        } else {
            hor[a].push_back(b);
            hor[c + 1].push_back(-b);
            vals.insert(a);
            vals.insert(c + 1);
        }
    }

    BIT<int> bit;
    bit.init(MAXXY * 2);

    long long sects = 0;

    for (auto i : vals) {
        for (auto j : hor[i]) {
            bit.add(abs(j), (j < 0 ? -1 : 1));
        }

        for (auto j : vert[i]) {
            sects += bit.sum(j.first, j.second);
        }
    }

    cout << sects << '\n';
}
