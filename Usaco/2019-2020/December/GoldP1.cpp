#include <bits/stdc++.h>
using namespace std;

// template {{{
typedef long long ll;
typedef long double ld;
typedef double db;
typedef string str;

typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<ld, ld> pd;

typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ll> vl;
typedef vector<ld> vd;
typedef vector<string> vs;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<pd> vpd;
#define vc vector


#define sz(x) (int)((x).size)
#define bg(x) begin(x)
#define rbg(x) rbegin(x)
#define all(x) bg(x), end(x)
#define rall(x) rbg(x), rend(x)
#define pb push_back
#define eb emplace_back
#define pf push_front
#define rsz resize
#define ins insert
#define ft front
#define bk back

#define ub upper_bound
#define lb lower_bound

#define f first
#define s second
#define mp make_pair

#define ln length

template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;

void IO(string s = "") {
    ios_base::sync_with_stdio(0); cin.tie(0); 
    if (s.length()) {
        freopen((s+".in").c_str(),"r",stdin);
        freopen((s+".out").c_str(),"w",stdout);
    }
} //}}}

const ld INF = 1e9;

int main() {
    IO("pump");

    int n, m;
    cin >> n >> m;
    vc<pair<int, pd>> v[n+1];
    for (int i = 0; i < m; i++) {
        int a, b;
        ld c, f;
        cin >> a >> b >> c >> f;
        v[a].pb({b, {c, f}});
        v[b].pb({a, {c, f}});
    }
    vb vis(n+1, false);
    vd dist(n+1, INF);
    set<pair<pair<ld, int>, pd>, greater<pair<pair<ld, int>, pd>>> s;
    s.insert({{INF, 1}, {0, INF}});
    while (!s.empty()) {
        pair<pair<ld, int>, pd> k = *s.begin();
        s.erase(s.begin());
        if (vis[k.f.s]) continue;
        vis[k.f.s] = true;
        dist[k.f.s] = k.f.f;
        for (auto i: v[k.f.s]) {
            ld f = min(k.s.s, i.s.s);
            ld c = k.s.f+i.s.f;
            s.insert({{f/c, i.f}, {c, f}});
        }
    }
    dist[n] *= 1000000;
    int ans = dist[n];
    cout << ans << '\n';
}
