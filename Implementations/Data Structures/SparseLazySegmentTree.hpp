struct Node {
	long long val;
	long long lzAdd;
	long long L, R;
	Node *c[2];
	Node(long long l, long long r) : L(l), R(r) {
		val = 0;
		lzAdd = 0;
		c[0] = c[1] = NULL;
	}
	void extend() {
		if (!c[0] && !c[1] && L != R) {
			long long M = (L + R) / 2;
			c[0] = new Node(L, M);
			c[1] = new Node(M + 1, R);
		}
	}
	void push() {
		val += (R - L + 1) * lzAdd;
		if (L != R) {
			c[0]->lzAdd += lzAdd;
			c[1]->lzAdd += lzAdd;
		}
		lzAdd = 0;
	}
	void upd(int lo, int hi, long long inc) {
		extend();
		push();
		if (lo > R || L > hi) return;
		if (lo <= L && R <= hi) {
			lzAdd += inc;
			push();
			return;
		}
		c[0]->upd(lo, hi, inc);
		c[1]->upd(lo, hi, inc);
		val = c[0]->val + c[1]->val;
	}
	long long query(int lo, int hi) {
		extend();
		push();
		if (lo > R || L > hi) return 0;
		if (lo <= L && R <= hi) return val;
		long long res = 0;
		res += c[0]->query(lo, hi);
		res += c[1]->query(lo, hi);
		return res;
	}
};
