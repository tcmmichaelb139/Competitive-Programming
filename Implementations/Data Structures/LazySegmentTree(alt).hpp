struct Node {
    long long val;
    long long lzAdd;
};

template <class T, int N>
struct LazySeg {
    static_assert(__builtin_popcount(N) == 1);
    const T ID = {0, 0};
    long long cmb(long long a, long long b) { return a + b; }
    T seg[2 * N];
    void push(int p, int L, int R) {
        seg[p].val += (R - L + 1) * seg[p].lzAdd;
        if (L != R) {
            seg[2 * p].lzAdd += seg[p].lzAdd;
            seg[2 * p + 1].lzAdd += seg[p].lzAdd;
        }
        seg[p].lzAdd = 0;
    }
    void pull(int p) { seg[p].val = cmb(seg[2 * p].val, seg[2 * p + 1].val); }
    void build(vector<long long> &v, int p = 1, int L = 0, int R = N - 1) {
        seg[p].lzAdd = ID.val;
        if (L == R) {
            if (size(v) > L)
                seg[p].val = v[L];
        } else {
            int M = (L + R) / 2;
            build(v, 2 * p, L, M);
            build(v, 2 * p + 1, M + 1, R);
            pull(p);
        }
    }
    void upd(int lo, int hi, long long inc, int p = 1, int L = 0, int R = N - 1) {
        push(p, L, R);
        if (lo > R || L > hi) return;
        if (lo <= L && R <= hi) {
            seg[p].lzAdd = inc;
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
        if (lo > R || L > hi) return ID.val;
        if (lo <= L && R <= hi) return seg[p].val;
        int M = (L + R) / 2;
        return cmb(query(lo, hi, 2 * p, L, M), query(lo, hi, 2 * p + 1, M + 1, R));
    }
};
