#include "bits/stdc++.h"
using namespace std;

template <class T>
struct Seg {
    const T ID = -1e18;
    T cmb(T a, T b) { return max(a, b); }
    int N;
    vector<T> seg;
    void init(int _N) {
        for (N = 1; N < _N;) N *= 2;
        seg.assign(2 * N, ID);
    }
    void pull(int p) { seg[p] = cmb(seg[2 * p], seg[2 * p + 1]); }
    void upd(int p, T val) {
        seg[p += N] = val;
        for (p /= 2; p; p /= 2) pull(p);
    }
    T query(int l, int r) {
        T ra = ID, rb = ID;
        for (l += N, r += N + 1; l < r; l /= 2, r /= 2) {
            if (l & 1) ra = cmb(ra, seg[l++]);
            if (r & 1) rb = cmb(rb, seg[--r]);
        }
        return cmb(ra, rb);
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    bool start = 0;
    while (cin >> n) {
        if (n == 0)
            break;
        if (start)
            cout << '\n';
        start = true;

        Seg<long long> seg;
        seg.init(n + 1);

        map<long long, int> ind;
        vector<pair<long long, long long>> v(n);
        vector<long long> time;
        for (int i = 0; i < n; i++) {
            cin >> v[i].first >> v[i].second;
            ind[v[i].first] = i;
            seg.upd(i, v[i].second);
            time.push_back(v[i].first);
        }

        cin >> m;
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            if (ind.find(a) != ind.end() && ind.find(b) != ind.end() && ind[b] - ind[a] == b - a && v[ind[a]].second >= v[ind[b]].second && seg.query(ind[a] + 1, ind[b] - 1) < v[ind[b]].second)
                cout << "true\n";
            else if (ind.find(a) == ind.end() || ind.find(b) == ind.end()) {
                if (ind.find(a) == ind.end() && ind.find(b) == ind.end())
                    cout << "maybe\n";
                else if (ind.find(a) == ind.end()) {
                    auto k = lower_bound(begin(time), end(time), a);
                    if (k == end(time))
                        cout << "maybe\n";
                    else {
                        int kk = k - begin(time);
                        if (seg.query(kk, ind[b] - 1) >= v[ind[b]].second)
                            cout << "false\n";
                        else
                            cout << "maybe\n";
                    }
                } else if (ind.find(b) == ind.end()) {
                    auto k = lower_bound(begin(time), end(time), b);
                    int kk;
                    if (k == end(time)) {
                        if (ind[a] == n - 1) {
                            cout << "maybe\n";
                            continue;
                        }
                        kk = n - 1;
                    } else
                        kk = k - begin(time) - 1;
                    if (seg.query(ind[a] + 1, kk) >= v[ind[a]].second)
                        cout << "false\n";
                    else
                        cout << "maybe\n";
                } else
                    assert(false);
            } else if (v[ind[a]].second < v[ind[b]].second || seg.query(ind[a] + 1, ind[b] - 1) >= v[ind[b]].second)
                cout << "false\n";
            else
                cout << "maybe\n";
        }
    }
    cin >> m;
}
