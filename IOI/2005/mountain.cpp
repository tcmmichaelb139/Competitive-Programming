#include "bits/stdc++.h"
using namespace std;

const int INF = 1'000'000'001;
struct Node {
	int sum;
	int mx;
	int L, R;
	bool lazy;
	Node *c[2];

	Node(int l, int r, int v) : L(l), R(r) {
		sum = mx = (r - l + 1) * v;
		lazy = false;
		c[0] = c[1] = NULL;
	}
	void set(int v) {
		sum = mx = (R - L + 1) * v;
	}
	void extend() {
		if (!c[0] && !c[1] && L != R) {
			int M = (L + R) / 2;
			c[0] = new Node(L, M, sum / (R - L + 1));
			c[1] = new Node(M + 1, R, sum / (R - L + 1));
		}
	}
	void push() {
		if (!lazy) return;
		if (L != R) {
			c[0]->lazy = c[1]->lazy = true;
			c[0]->set(sum / (R - L + 1));
			c[1]->set(sum / (R - L + 1));
		}
		lazy = false;
	}
	void upd(int lo, int hi, int inc) {
		if (lo > R || L > hi) return;
		if (lo <= L && R <= hi) {
			sum = mx = (R - L + 1) * inc;
			lazy = true;
			return;
		}

		extend();
		push();

		c[0]->upd(lo, hi, inc);
		c[1]->upd(lo, hi, inc);

		mx = max(c[0]->mx, c[0]->sum + c[1]->mx);
		sum = c[0]->sum + c[1]->sum;
	}
	int query(int h) {
		if (L == R) return L - 1;
		if (mx <= h) return R;
		extend();
		push();
		if (c[0]->mx > h) return c[0]->query(h);
		else return c[1]->query(h - c[0]->sum);
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	Node seg(1, n, 0);

	char c;
	while (cin >> c) {
		if (c == 'Q') {
			int h;
			cin >> h;
			cout << seg.query(h) << '\n';
		} else if (c == 'I') {
			int a, b, d;
			cin >> a >> b >> d;
			seg.upd(a, b, d);
		} else if (c == 'E') {
			return 0;
		} else
			assert(false);
	}
}
