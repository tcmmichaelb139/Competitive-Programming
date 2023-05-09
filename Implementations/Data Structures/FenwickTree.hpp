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
