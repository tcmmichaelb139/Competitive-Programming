#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;

typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<double, double> pd;

typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ll> vl;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<pd> vpd;

#define vc vector
#define pb push_back
#define pf push_front
#define rsz resize
#define sz size
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define ub upper_bound
#define lb lower_bound

#define f first
#define s second

#define ln length
#define IMX INT_MAX
#define IMN INT_MIN

void IO(string s = "") {
    ios_base::sync_with_stdio(0); cin.tie(0); 
    if (s.length()) {
        freopen((s+".in").c_str(),"r",stdin);
        freopen((s+".out").c_str(),"w",stdout);
    }
}

bool cmp(pi a, pi b) {
    if (a.s == b.s) return a.f < b.s;
    return a.s < b.s;
}

int main() {
    IO("rental");

    int n, m, r;
    cin >> n >> m >> r;
    vl c(n);
    vpl qp(m);
    vl f(r);
    for (int i = 0; i < n; i++) cin >> c[i];
    for (int i = 0; i < m; i++) cin >> qp[i].f >> qp[i].s;
    for (int i = 0; i < r; i++) cin >> f[i];
    sort(all(c));
    sort(rall(qp), cmp);
    sort(all(f));
    for (int i = r-2; i >= 0; i--) f[i] += f[i+1];
    //for (int i = 0; i < r; i++) cout << f[i] << '\n';
    ll sold = 0;
    ll ans = f[r-min(n, r)];
    int currstore = 0;
    for (int i = n-1; i >= 0; i--) {
        while (c[i] > 0 && currstore < m) {
            if (qp[currstore].f <= c[i]) {
                sold += qp[currstore].s*qp[currstore].f;
                c[i] -= qp[currstore].f;
                currstore++;
            }
            else {
                sold += qp[currstore].s*c[i];
                qp[currstore].f -= c[i];
                c[i] = 0;
            }
        }
        ans = max(ans, sold+(i == 0 ? 0 : f[r-min(i, r)]));
    }
    cout << ans << '\n';
}
