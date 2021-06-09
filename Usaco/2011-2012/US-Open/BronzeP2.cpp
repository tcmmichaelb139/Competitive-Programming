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
#define mp make_pair

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

int main() {
    IO("");

    int n;
    cin >> n;
    vpi v(n);
    set<int> x, y;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        x.insert(a);
        y.insert(b);
        v[i] = {a, b};
    }
    int ans = 0;
    if (x.sz() <= 3) ans++;
    if (y.sz() <= 3) ans++;
    for (auto j: x) {
        set<int> temp;
        map<int, int> m;
        for (int i = 0; i < n; i++) {
            if (temp.sz() > 2) break;
            if (v[i].f == j) continue;
            temp.insert(v[i].s);
            m[v[i].s]++;
        }
        if (temp.sz() <= 2) {
            for (auto a: m)
                if (a.s == 1) {
                    ans--;
                    break;
                }
            ans++;
        }
        cout << ans << '\n';
    }
    for (auto j: y) {
        set<int> temp;
        for (int i = 0; i < n; i++) {
            if (temp.sz() > 2) break;
            if (v[i].s == j) continue;
            temp.insert(v[i].f);
        }
        if (temp.sz() <= 2) ans++;
    }
    cout << ans << '\n';
}

