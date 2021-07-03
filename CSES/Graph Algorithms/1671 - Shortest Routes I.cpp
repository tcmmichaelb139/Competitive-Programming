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

#define ve vector
typedef ve<int> vi;
typedef ve<bool> vb;
typedef ve<ll> vl;
typedef ve<ld> vd;
typedef ve<string> vs;
typedef ve<pi> vpi;
typedef ve<pl> vpl;
typedef ve<pd> vpd;

#define sz(x) (int)((x).size())
#define bg(x) begin(x)
#define rbg(x) rbegin(x)
#define all(x) x.begin(), x.end()
#define rall(x) rbg(x), rend(x)
#define pb push_back
#define eb emplace_back
#define pf push_front
#define rsz resize
#define ins insert

#define ub upper_bound
#define lb lower_bound

#define f first
#define s second
#define mp make_pair

#define ln length

template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
template<class T> using setg = set<T, greater<T>>;

const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

void IO(string s = "") {
    ios_base::sync_with_stdio(0); cin.tie(0); 
    if (s.length()) {
        freopen((s+".in").c_str(),"r",stdin);
        freopen((s+".out").c_str(),"w",stdout);
    }
} //}}}

int main() {
    IO("");

    int n, m;
    cin >> n >> m;
    vpl adj[n+1];
    for (int i = 0; i < m; i++) {
        ll a, b, w;
        cin >> a >> b >> w;
        adj[a].pb({w, b});
    }
    vl dist(n+1);
    vb vis(n+1, false);
    pqg<pl> q;
    q.push({0, 1});
    while (!q.empty()) {
        pl k = q.top();
        q.pop();
        if (vis[k.s]) continue;
        vis[k.s] = true;
        dist[k.s] = k.f;
        for (auto i: adj[k.s]) {
            q.push({k.f+i.f, i.s});
        }
    }
    for (int i = 1; i <= n; i++) cout << dist[i] << ' ';
    cout << '\n';
}

/* Stuff to look for 
 * int overflow, array bounds
 * special cases (n=1)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 * GET RID OF DEBUGGING CODE BEFORE SUBMITTING
 */
