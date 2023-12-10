#include "bits/stdc++.h"
using namespace std;

template <class T>
struct Seg {
	const T ID = 0;
	T cmb(T a, T b) { return a + b; }
	int N;
	vector<T> seg;
	void init(int _N) {
		for (N = 1; N < _N;) N *= 2;
		seg.assign(2 * N, ID);
	}
	void pull(int p) { seg[p] = cmb(seg[2 * p], seg[2 * p + 1]); }
	void upd(int p, T val) {
		seg[p += N] = val;
		for (p /= 2; p; p /= 2) pull(p);
	}
	T query(int l, int r) {
		T ra = ID, rb = ID;
		for (l += N, r += N + 1; l < r; l /= 2, r /= 2) {
			if (l & 1) ra = cmb(ra, seg[l++]);
			if (r & 1) rb = cmb(rb, seg[--r]);
		}
		return cmb(ra, rb);
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> prev(n, -1);
	Seg<long long> seg;
	seg.init(n);

	long long ans = 0;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		a--;

		ans += seg.query(prev[a] + 1, i);

		if (prev[a] != -1)
			seg.upd(prev[a], 0);
		prev[a] = i;
		seg.upd(prev[a], 1);
	}

	cout << ans << '\n';
}
