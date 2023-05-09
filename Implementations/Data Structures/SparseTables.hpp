template <class T>
struct SparseTable {
    int level(int x) { return 31 - __builtin_clz(x); }
    vector<T> v;
    vector<vector<int>> jmp;
    int cmb(int a, int b) {
        return v[a] == v[b] ? min(a, b) : (v[a] < v[b] ? a : b);
    }
    void init(const vector<T>& _v) {
        v = _v;
        jmp = {vector<int>(size(v))};
        iota(begin(jmp[0]), end(jmp[0]), 0);
        for (int j = 1; 1 << j <= size(v); ++j) {
            jmp.push_back(vector<int>(size(v) - (1 << j) + 1));
            for (int i = 0; i < size(jmp[j]); i++)
                jmp[j][i] = cmb(jmp[j - 1][i], jmp[j - 1][i + (1 << (j - 1))]);
        }
    }
    int index(int l, int r) {
        assert(l <= r);
        int d = level(r - l + 1);
        return cmb(jmp[d][l], jmp[d][r - (1 << d) + 1]);
    }
    T query(int l, int r) { return v[index(l, r)]; }
};
