const long double EPS = 1e-9;
template <class T>
struct P {
    T x, y;
    P() : x(0), y(0) {}
    P(T a, T b) : x(a), y(b) {}

    friend ostream &operator<<(ostream &o, const P &p) { return o << '(' << p.x << ',' << p.y << ')'; }
    friend istream &operator>>(istream &i, P &p) { return i >> p.x >> p.y; }

    friend bool operator==(const P &a, const P &b) { return a.x - b.x < EPS && a.y - b.y < EPS; }

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
