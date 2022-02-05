#include<bits/stdc++.h>
using namespace std;

template<class T> struct Seg { 
	const T ID = 0; T cmb(T a, T b) { return max(a, b); } 
	int n; vector<T> seg;
	void init(int _n) { 
        for (n = 1; n < _n; ) n *= 2;
        seg.assign(2*n, ID); }
	void pull(int p) { seg[p] = cmb(seg[2*p],seg[2*p+1]); }
	void upd(int p, T val) { 
		seg[p += n] = val; for (p /= 2; p; p /= 2) pull(p); }
	T query(int l, int r) {	
		T ra = ID, rb = ID;
		for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
			if (l&1) ra = cmb(ra,seg[l++]);
			if (r&1) rb = cmb(seg[--r],rb);
		}
		return cmb(ra,rb);
	}
};

long long n, m;

int main() {
	freopen("hayfeast.in", "r", stdin);
	freopen("hayfeast.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;
	vector<pair<long long, long long>> v(n);
	Seg<long long> spice; spice.init(n+1);
	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
		spice.upd(i, v[i].second);
	}
	int r = 0;
	long long flavor = 0;
	long long ans = 1e18+1;
	for (int l = 0; l < n; l++) {
		while (r != n && flavor < m) {
			flavor += v[r].first;
			r++;
		}
		if (flavor >= m)
			ans = min(ans, spice.query(l, r));
		flavor -= v[l].first;
	}
	cout << ans << '\n';
}
