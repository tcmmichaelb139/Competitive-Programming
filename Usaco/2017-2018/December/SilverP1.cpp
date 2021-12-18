#include <bits/stdc++.h>
using namespace std;

template<class T> struct Seg {
	const T ID = 1e9; T cmb(T a, T b) { return min(a, b); };
	int n; vector<T> v;
	void init(int _n) {
		for (n = 1; n < _n; ) n *= 2;
		v.assign(2*n, ID);
	}
	void pull(int p) { v[p] = cmb(v[2*p], v[2*p+1]); }
	void upd(int p, T val) {
		v[p += n] = val; for (p /= 2; p; p /= 2) pull(p);
	}
	T query(int l, int r) {
		T ra = ID, rb = ID;
		for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
			if (l&1) ra = cmb(ra, v[l++]);
			if (r&1) rb = cmb(rb, v[--r]);
		}
		return cmb(ra, rb);
	}
};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("homework.in", "r", stdin);
	freopen("homework.out", "w", stdout);

	double n; cin >> n;
	int sum = 0;
	Seg<int> seg;
	seg.init(n);
	vector<int> v(n+1);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		sum += v[i];
		seg.upd(i, v[i]);
	}
	double ans = 0;
	double sum2 = sum;
	for (double i = 0; i < n; i++) {
		double mn = seg.query(i, n-1);
		double tmp = sum2-mn;
		ans = max(ans, tmp/(n-i-1));
		sum2 -= v[i];
	}
	vector<int> sol;
	for (double i = 0; i < n-1; i++) {
		double mn = seg.query(i, n-1);
		double tmp = sum-mn;
		if (ans == tmp/(n-i-1)) {
			sol.push_back(i);
		}
		sum -= v[i];
	}
	for (int i = 0; i < sol.size(); i++) 
		if (sol[i] != 0)
			cout << sol[i] << '\n';
}

