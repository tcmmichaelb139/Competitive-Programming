struct DSU {
    vector<int> v;
    void init(int n) { v = vector<int>(n, -1); }
    int sameSet(int a, int b) { return get(a) == get(b); }
    int get(int a) { return v[a] < 0 ? a : v[a] = get(v[a]); }
    int size(int a) { return -v[get(a)]; }
    int unite(int a, int b) {
        a = get(a), b = get(b);
        if (a == b) return false;
        if (v[a] > v[b]) swap(a, b);
        v[a] += v[b];
        v[b] = a;
        return true;
    }
};
