#include<bits/stdc++.h>
using namespace std;

template<class T> struct BIT {
	int n; vector<T> v;
	void init(int _n) { n = _n; v.resize(n); }
	void add(int p, T x) { for (++p; p <= n; p += p&-p) v[p-1] += x; }
	T sum(int l, int r) { return sum(r+1)-sum(l); }
	T sum(int r) { T s = 0; for (; r; r -= r&-r) s += v[r-1]; return s; }
	void print() { for (int i = 0; i < n; i++) cout << v[i] << " \n"[i+1 == n]; }
};

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n, q; cin >> n >> q;
	BIT<long long> bit; bit.init(n+1);
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		bit.add(i, v[i]);
	}
	for (int i = 0; i < q; i++) {
		int a, b, c; cin >> a >> b >> c;
		a--;
		if (a) {
			cout << bit.sum(b-1, c-1) << '\n';
		} else {
			bit.add(b-1, c-v[b-1]);
			v[b-1] = c;
		}
	}
}
