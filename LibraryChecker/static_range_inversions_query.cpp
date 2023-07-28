#include "bits/stdc++.h"
using namespace std;

const int SQ = 320;

struct Query {
	int l, r;
	int i;

	bool operator<(const Query &o) const {
		if (l / SQ == o.l / SQ) return r < o.r;
		return l / SQ < o.l / SQ;
	}
};

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

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, q;
	cin >> n >> q;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	vector<Query> que(q);
	for (int i = 0; i < q; i++) {
		cin >> que[i].l >> que[i].r;
		que[i].i = i;
	}

	vector<int> cc = v;
	sort(begin(cc), end(cc));
	cc.erase(unique(begin(cc), end(cc)), end(cc));

	for (int i = 0; i < n; i++)
		v[i] = (int)(lower_bound(begin(cc), end(cc), v[i]) - begin(cc)) + 1;

	sort(begin(que), end(que));

	BIT<long long> bit;
	bit.init(n + 1);

	long long cans = 0;

	int l = 0, r = -1;

	auto modify = [&](int x, int m, bool lr) {
		if (lr) cans += m * bit.sum(v[x] + 1, n);
		else cans += m * bit.sum(1, v[x] - 1);

		bit.add(v[x], m);
	};

	auto upd = [&](int L, int R) {
		while (r < R) modify(++r, 1, 1);
		while (l > L) modify(--l, 1, 0);
		while (r > R) modify(r--, -1, 1);
		while (l < L) modify(l++, -1, 0);
	};

	vector<long long> ans(q);

	for (int i = 0; i < q; i++) {
		upd(que[i].l, que[i].r - 1);

		ans[que[i].i] = cans;
	}

	for (int i = 0; i < q; i++)
		cout << ans[i] << '\n';
}
