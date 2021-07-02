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

int n, m, c;
vpi adj[100001];
int p[100001];
int ans[100001];

void topo(int k) {
    if (p[k] > 0) return;
    for (auto i: adj[k]) {
        p[i.s]--;
        ans[i.s] = max(ans[i.s], ans[k]+i.f);
        topo(i.s);
    }
}

int main() {
    IO("timeline");

    cin >> n >> m >> c;
    for (int i = 0; i < n; i++) {
        int e;
        cin >> e;
        adj[0].pb({e, i+1});
        p[i+1]++;
    }
    for (int i = 0; i < c; i++) {
        int a, b, x;
        cin >> a >> b >> x;
        adj[a].pb({x, b});
        p[b]++;
        /* adj[b].pb({x, a}); */
    }
    topo(0);
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << '\n';
    }
}

