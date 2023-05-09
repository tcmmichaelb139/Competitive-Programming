template <class T, int N>
struct LazySeg {
    static_assert(__builtin_popcount(N) == 1);
    const T ID = {};
    T cmb(T a, T b) { return a + b; }
    T seg[2 * N], lazy[2 * N];
    LazySeg() {
        for (int i = 0; i < 2 * N; i++)
            seg[i] = lazy[i] = ID;
    }
    void push(int p, int L, int R) {
        seg[p] += (R - L + 1) * lazy[p];
        if (L != R) {
            lazy[2 * p] += lazy[p];
            lazy[2 * p + 1] += lazy[p];
        }
        lazy[p] = 0;
    }
    void pull(int p) { seg[p] = cmb(seg[2 * p], seg[2 * p + 1]); }
    void build() {
        for (int i = N - 1; i >= 1; i--)
            pull(i);
    }
    void upd(int lo, int hi, T inc, int p = 1, int L = 0, int R = N - 1) {
        push(p, L, R);
        if (lo > R || L > hi) return;
        if (lo <= L && R <= hi) {
            lazy[p] = inc;
            push(p, L, R);
            return;
        }
        int M = (L + R) / 2;
        upd(lo, hi, inc, 2 * p, L, M);
        upd(lo, hi, inc, 2 * p + 1, M + 1, R);
        pull(p);
    }
    T query(int lo, int hi, int p = 1, int L = 0, int R = N - 1) {
        push(p, L, R);
        if (lo > R || L > hi) return ID;
        if (lo <= L && R <= hi) return seg[p];
        int M = (L + R) / 2;
        return cmb(query(lo, hi, 2 * p, L, M), query(lo, hi, 2 * p + 1, M + 1, R));
    }
};
