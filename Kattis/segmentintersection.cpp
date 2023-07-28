#include "bits/stdc++.h"
using namespace std;

const long double EPS = 1e-9;
template <class T>
struct P {
	T x, y;
	P() : x(0), y(0) {}
	P(T a, T b) : x(a), y(b) {}

	friend ostream &operator<<(ostream &o, const P &p) { return o << '(' << p.x << ',' << p.y << ')'; }
	friend istream &operator>>(istream &i, P &p) { return i >> p.x >> p.y; }

	friend bool operator==(const P &a, const P &b) { return fabs(a.x - b.x) < EPS && fabs(a.y - b.y) < EPS; }

	P operator-() { return P(-x, -y); }

	friend P operator+(const P &a, const P &b) { return P(a.x + b.x, a.y + b.y); }
	friend P operator-(const P &a, const P &b) { return P(a.x - b.x, a.y - b.y); }
	friend P operator*(const P &a, const T &t) { return P(a.x * t, a.y * t); }
	friend P operator*(const T &t, const P &a) { return P(t * a.x, t * a.y); }
	friend P operator/(const P &a, const T &b) { return P(a.x / b, a.y / b); }

	friend T dot(const P &a, const P &b) { return a.x * b.x + a.y * b.y; }
	friend T cross(const P &a, const P &b) { return a.x * b.y - a.y * b.x; }

	P &operator+=(const P &b) { return *this = *this + b; }
	P &operator-=(const P &b) { return *this = *this - b; }
	P &operator*=(const T &b) { return *this = *this * b; }
	P &operator/=(const T &b) { return *this = *this / b; }

	T dist2() const { return x * x + y * y; }
	auto dist() const { return sqrt(dist2()); }
	P unit() const { return *this / this->dist(); }
	auto angle() const { return atan2(y, x); }

	friend auto norm(const P &a) { return a.dist2(); }
	friend auto abs(const P &a) { return a.dist(); }
	friend auto unit(const P &a) { return a.unit(); }
	friend auto arg(const P &a) { return a.angle(); }
};

template <class T>
struct Line {
	T a, b, c;
	void pointsToLine(P<T> p1, P<T> p2) {
		if (fabs(p1.x - p2.x) < EPS)
			a = 1.0, b = 0.0, c = -p1.x;
		else {
			a = -(p1.y - p2.y) / (p1.x - p2.x);
			b = 1.0;
			c = -(a * p1.x) - p1.y;
		}
	}
	bool parallel(Line<T> o) {
		return (fabs(a - o.a) < EPS) && (fabs(b - o.b) < EPS);
	}
	bool intersect(Line<T> o, P<T> &p) {
		if (parallel(o)) return false;

		p.x = (b * o.c - o.b * c) / (a * o.b - o.a * b);
		if (b > EPS) p.y = -(a * p.x + c) / b;
		else p.y = -(o.a * p.x + o.c) / o.b;

		return true;
	}
	bool onLine(P<T> p) {
		return fabs(a * p.x + b * p.y + c) < EPS;
	}
};

bool between(P<double> p1, P<double> p2, P<double> m) {
	bool bx = false, by = false;
	if (m == p1 || m == p2) return true;
	if (p1.x <= m.x && m.x <= p2.x) bx = true;
	if (p1.y <= m.y && m.y <= p2.y) by = true;
	if (p2.x <= m.x && m.x <= p1.x) bx = true;
	if (p2.y <= m.y && m.y <= p1.y) by = true;
	return bx && by;
}

void solve() {
	P<double> p1, p2, p3, p4;
	cin >> p1 >> p2 >> p3 >> p4;
	Line<double> l1, l2;
	l1.pointsToLine(p1, p2);
	l2.pointsToLine(p3, p4);
	/* cout << l1.a << ' ' << l1.b << ' ' << l1.c << '\n'; */
	/* cout << l2.a << ' ' << l2.b << ' ' << l2.c << '\n'; */
	P<double> sect;
	if (p1 == p2 && p3 == p4) {
		if (p1 == p3) cout << p1.x << ' ' << p1.y << '\n';
		else cout << "none\n";
	} else if (p1 == p2) {
		if (l2.onLine(p1)) cout << p1.x << ' ' << p1.y << '\n';
		else cout << "none\n";
	} else if (p3 == p4) {
		if (l1.onLine(p3)) cout << p3.x << ' ' << p3.y << '\n';
		else cout << "none\n";
	} else if (l1.intersect(l2, sect)) {
		if (abs(sect.x) < EPS) sect.x = abs(sect.x);
		if (abs(sect.y) < EPS) sect.y = abs(sect.y);
		if (between(p1, p2, sect) && between(p3, p4, sect)) cout << sect.x << ' ' << sect.y << '\n';
		else cout << "none\n";
	} else {
		if (l1.b < EPS && l2.b < EPS) {
			if (p1.y > p2.y) swap(p1, p2);
			if (p3.y > p4.y) swap(p3, p4);
			if (p2.y < p3.y || p4.y < p1.y || fabs(l1.c - l2.c) > EPS) {
				cout << "none\n";
			} else {
				vector<P<double>> points = {p1, p2, p3, p4};
				sort(begin(points), end(points), [](P<double> &a, P<double> &b) { return a.y < b.y; });
				if (points[1] == points[2])
					cout << points[1].x << ' ' << points[1].y << '\n';
				else
					cout << points[1].x << ' ' << points[1].y << ' ' << points[2].x << ' ' << points[2].y << '\n';
			}
		} else {
			if (p1.x > p2.x) swap(p1, p2);
			if (p3.x > p4.x) swap(p3, p4);
			if (p2.x < p3.x || p4.x < p1.x || fabs(l1.c - l2.c) > EPS) {
				cout << "none\n";
			} else {
				vector<P<double>> points = {p1, p2, p3, p4};
				sort(begin(points), end(points), [](P<double> &a, P<double> &b) { return a.x < b.x; });
				if (points[1] == points[2])
					cout << points[1].x << ' ' << points[1].y << '\n';
				else
					cout << points[1].x << ' ' << points[1].y << ' ' << points[2].x << ' ' << points[2].y << '\n';
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cout << setprecision(2) << fixed;

	int t;
	cin >> t;
	while (t--) solve();
}
