#include "bits/stdc++.h"
using namespace std;

struct SpringBoard {
	int x1, y1;
	int x2, y2;
};

struct Point {
	int x, y;
};

template <class T>
struct Seg {
	const T ID = 0;
	T cmb(T a, T b) { return min(a, b); }
	int N;
	vector<T> seg;
	void init(int _N) {
		for (N = 1; N < _N;) N *= 2;
		seg.assign(2 * N, ID);
	}
	void pull(int p) { seg[p] = cmb(seg[2 * p], seg[2 * p + 1]); }
	void upd(int p, T val) {
		p += N;
		seg[p] = min(seg[p], val);
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
	freopen("boards.in", "r", stdin);
	freopen("boards.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<SpringBoard> p;
	vector<int> ccx = {0, n}, ccy = {0, n};
	for (int i = 0; i < m; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		p.push_back({a, b, c, d});
		ccx.push_back(a);
		ccx.push_back(c);
		ccy.push_back(b);
		ccy.push_back(d);
	}

	sort(begin(ccx), end(ccx));
	ccx.erase(unique(begin(ccx), end(ccx)), end(ccx));
	for (int i = 0; i < m; i++) {
		p[i].x1 = (int)(lower_bound(begin(ccx), end(ccx), p[i].x1) - begin(ccx));
		p[i].x2 = (int)(lower_bound(begin(ccx), end(ccx), p[i].x2) - begin(ccx));
	}
	sort(begin(ccy), end(ccy));
	ccy.erase(unique(begin(ccy), end(ccy)), end(ccy));
	for (int i = 0; i < m; i++) {
		p[i].y1 = (int)(lower_bound(begin(ccy), end(ccy), p[i].y1) - begin(ccy));
		p[i].y2 = (int)(lower_bound(begin(ccy), end(ccy), p[i].y2) - begin(ccy));
	}

	int nx = (int)size(ccx), ny = (int)size(ccy);
	vector<pair<int, Point>> pts[nx];
	for (int i = 0; i < m; i++) {
		pts[p[i].x1].push_back({p[i].y1, {p[i].x2, p[i].y2}});
	}

	auto save = [&](int x1, int y1, int x2, int y2) {
		return -ccx[x2] + ccx[x1] - ccy[y2] + ccy[y1];
	};

	Seg<int> seg;
	seg.init(ny);

	vector<Point> upd[nx];

	for (int i = 0; i < nx; i++) {
		sort(begin(pts[i]), end(pts[i]), [](pair<int, Point> a, pair<int, Point> b) { return a.second.y < b.second.y; });
		for (auto j : upd[i]) {
			seg.upd(j.x, j.y);
		}
		for (auto j : pts[i]) {
			int q = seg.query(0, j.first);
			if (j.second.x == i) {
				seg.upd(j.second.y, q + save(i, j.first, j.second.x, j.second.y));
			} else {
				upd[j.second.x].push_back({j.second.y, q + save(i, j.first, j.second.x, j.second.y)});
			}
		}
	}

	cout << seg.query(0, ny) + 2 * n << '\n';
}
