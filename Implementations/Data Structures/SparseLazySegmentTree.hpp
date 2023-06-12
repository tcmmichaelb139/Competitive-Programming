template <int N>
struct Node {
	static_assert(__builtin_popcount(N) == 1);
	long long val;
	long long lzAdd;
	long long L, R;
	Node *c[2];
	Node(int l, int r) : L(l), R(r) {
		val = 0;
		lzAdd = 0;
		c[0] = c[1] = NULL;
	}
	void push() {
		val += (R - L + 1) * lzAdd;
		if (L != R) {
			c[0]->lzAdd += lzAdd;
			c[1]->lzAdd += lzAdd;
		}
		lzAdd = 0;
	}
	void pull() { val = c[0]->val + c[1]->val; }
	void build(vector<long long> &v) {
		lzAdd = 0;
		if (L == R) {
			if (size(v) > L)
				val = v[L];
		} else {
			int M = (L + R) / 2;
			if (!c[0]) c[0] = new Node();
			c[0]->build(v, L, M);
			if (!c[1]) c[1] = new Node();
			c[1]->build(v, M + 1, R);
			pull();
		}
	}
	void upd(int lo, int hi, long long inc) {
		push(L, R);
		if (lo > R || L > hi) return;
		if (lo <= L && R <= hi) {
			lzAdd += inc;
			push(L, R);
			return;
		}
		int M = (L + R) / 2;
		if (c[0]) c[0]->upd(lo, hi, inc, L, M);
		if (c[1]) c[1]->upd(lo, hi, inc, M + 1, R);
		pull();
	}
	long long query(int lo, int hi) {
		push(L, R);
		if (lo > R || L > hi) return 0;
		if (lo <= L && R <= hi) return val;
		int M = (L + R) / 2;
		long long res = 0;
		if (c[0]) res += c[0]->query(lo, hi, L, M);
		if (c[1]) res += c[1]->query(lo, hi, M + 1, R);
		return res;
	}
};
