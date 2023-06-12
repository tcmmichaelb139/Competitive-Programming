#include "wall.h"
#include "bits/stdc++.h"
using namespace std;

struct Node {
	long long val;
	long long gt;
	long long lt;
};

template <class T, int N>
struct LazySeg {
	static_assert(__builtin_popcount(N) == 1);
	const T ID = {0, 0, (long long)1e18};
	long long cmb(long long a, long long b) { return a + b; }
	T seg[2 * N];
	LazySeg() {
		for (int i = 0; i < 2 * N; i++)
			seg[i] = ID;
	}
	void push(int p, int L, int R) {
		seg[p].val = max(seg[p].val, seg[p].gt);
		seg[p].val = min(seg[p].val, seg[p].lt);
		if (L != R) {
			if (seg[p].lt < seg[2 * p].gt) {
				seg[2 * p].gt = seg[2 * p].lt = seg[p].lt;
			} else if (seg[p].gt > seg[2 * p].lt) {
				seg[2 * p].gt = seg[2 * p].lt = seg[p].gt;
			} else {
				seg[2 * p].gt = max(seg[2 * p].gt, seg[p].gt);
				seg[2 * p].lt = min(seg[2 * p].lt, seg[p].lt);
			}
			if (seg[p].lt < seg[2 * p + 1].gt) {
				seg[2 * p + 1].gt = seg[2 * p + 1].lt = seg[p].lt;
			} else if (seg[p].gt > seg[2 * p + 1].lt) {
				seg[2 * p + 1].gt = seg[2 * p + 1].lt = seg[p].gt;
			} else {
				seg[2 * p + 1].gt = max(seg[2 * p + 1].gt, seg[p].gt);
				seg[2 * p + 1].lt = min(seg[2 * p + 1].lt, seg[p].lt);
			}
		}
		seg[p].gt = 0;
		seg[p].lt = 1e18;
	}
	void pull(int p) { seg[p].val = cmb(seg[2 * p].val, seg[2 * p + 1].val); }
	void upd(int lo, int hi, pair<int, long long> inc, int p = 1, int L = 0, int R = N - 1) {
		push(p, L, R);
		if (lo > R || L > hi) return;
		if (lo <= L && R <= hi) {
			if (inc.first == 1) {
				seg[p].gt = inc.second;
			} else {
				seg[p].lt = inc.second;
			}
			push(p, L, R);
			return;
		}
		int M = (L + R) / 2;
		upd(lo, hi, inc, 2 * p, L, M);
		upd(lo, hi, inc, 2 * p + 1, M + 1, R);
		pull(p);
	}
	long long query(int lo, int hi, int p = 1, int L = 0, int R = N - 1) {
		push(p, L, R);
		if (lo > R || L > hi) return ID.val;
		if (lo <= L && R <= hi) return seg[p].val;
		int M = (L + R) / 2;
		return cmb(query(lo, hi, 2 * p, L, M), query(lo, hi, 2 * p + 1, M + 1, R));
	}
};

void buildWall(int n, int k, int op[], int left[], int right[], int height[], int finalHeight[]) {
	LazySeg<Node, 1 << 21> seg;

	for (int i = 0; i < k; i++) {
		seg.upd(left[i], right[i], {op[i], height[i]});
	}

	for (int i = 0; i < n; i++) {
		finalHeight[i] = seg.query(i, i);
	}

	return;
}
