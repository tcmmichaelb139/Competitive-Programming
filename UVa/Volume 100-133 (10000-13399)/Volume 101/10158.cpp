#include "bits/stdc++.h"
using namespace std;

struct DSU {
    vector<int> v;
    vector<int> e;
    void init(int n) {
        v = vector<int>(n, -1);
        e = vector<int>(n, -1);
    }
    int sameSet(int a, int b) { return get(a) == get(b); }
    int get(int a) {
        return v[a] < 0 ? a : v[a] = get(v[a]);
    }
    int gete(int a) { return e[get(a)] < 0 ? e[get(a)] : get(e[get(a)]); }
    int unitef(int a, int b) {
        a = get(a), b = get(b);
        if (a == b) return false;
        if (gete(a) >= 0 || gete(b) >= 0) {
            int enemy = (gete(a) < 0 ? gete(b) : gete(a));
            if (gete(a) >= 0 && gete(b) >= 0)
                v[gete(b)] = enemy;
            e[a] = e[b] = enemy;
        }
        assert(b != a);
        v[b] = a;
        return true;
    }
    int unitee(int a, int b) {
        a = get(a), b = get(b);
        int ae = gete(a), be = gete(b);
        if (be >= 0 && be != a)
            v[be] = a;
        if (ae >= 0 && ae != b)
            v[ae] = b;
        e[a] = b;
        e[b] = a;
        return true;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    DSU dsu;
    dsu.init(n);

    auto setFriends = [&](int a, int b) {
        dsu.unitef(a, b);
    };

    auto areFriends = [&](int a, int b) {
        return dsu.sameSet(a, b);
    };

    auto setEnemies = [&](int a, int b) {
        dsu.unitee(a, b);
    };

    auto areEnemies = [&](int a, int b) {
        return dsu.gete(a) == dsu.get(b);
    };

    int a, b, c;
    while (cin >> a >> b >> c) {
        if (a == 1) {
            if (areEnemies(b, c) || areEnemies(c, b))
                cout << -1 << '\n';
            else {
                setFriends(b, c);
            }
        } else if (a == 2) {
            if (areFriends(b, c) || areFriends(c, b))
                cout << -1 << '\n';
            else
                setEnemies(b, c);
        } else if (a == 3) {
            cout << areFriends(b, c) << '\n';
        } else if (a == 4) {
            cout << areEnemies(b, c) << '\n';
        } else
            break;
    }
}
