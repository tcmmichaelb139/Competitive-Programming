#include <bits/stdc++.h>
using namespace std;

// template {{{
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
#define IMX 1e9
#define IMN -1e9

void IO(string s = "") {
    ios_base::sync_with_stdio(0); cin.tie(0); 
    if (s.length()) {
        freopen((s+".in").c_str(),"r",stdin);
        freopen((s+".out").c_str(),"w",stdout);
    }
}
//}}}

int main() {
    IO("rblock");

    int n, m;
    cin >> n >> m;
    vc<vpl> v(n+1);
    vc<vl> ar(n+1, vl(n+1, IMX));
    for (int i = 0; i < m; i++) {
        ll a, b, w;
        cin >> a >> b >> w;
        v[a].pb({b, w});
        v[b].pb({a, w});
        ar[a][b] = w;
        ar[b][a] = w;
    }
    vl dist(n+1, IMX);
    vb vis(n+1, false);
    vl p(n+1);
    dist[1] = 0;
    p[1] = -1;
    for (int i = 0; i < n; i++) {
        ll k = -1;
        for (int j = 1; j <= n; j++) {
            if (!vis[j] && (k == -1 || dist[j] < dist[k]))
                k = j;
        }
        if (dist[k] == IMX) break;
        vis[k] = true;
        for (auto j: v[k]) {
            if (dist[j.f] > dist[k]+j.s) {
                dist[j.f] = dist[k]+j.s;
                p[j.f] = k;
            }
        }
    }
    ll fs = 0;
    ll ss = 0;
    vl paths;
    for (int a = n; a != -1; a = p[a]) {
        paths.pb(a);
    }
    for (int i = 0; i < paths.sz()-1; i++) {
        fs += ar[paths[i]][paths[i+1]];
    }
    for (int a = 0; a < paths.sz()-1; a++) {
        vc<vpl> v2 = v;
        pl hay = {paths[a], paths[a+1]};
        vc<vl> ar2 = ar;
        ar2[hay.f][hay.s] *= 2;
        ar2[hay.s][hay.f] *= 2;
        for (int b = 0; b < v2[hay.f].sz(); b++) {
            if (v2[hay.f][b].f == hay.s) {
                v2[hay.f][b].s *= 2;
            }
        }
        for (int b = 0; b < v2[hay.s].sz(); b++) {
            if (v2[hay.s][b].f == hay.f) 
                v2[hay.s][b].s *= 2;
        }
        vl dist2(n+1, IMX);
        vl vis2(n+1, false);
        vl p2(n+1);
        dist2[1] = 0;
        p2[1] = -1;
        for (int i = 0; i < n; i++) {
            ll k = -1;
            for (int j = 1; j <= n; j++) {
                if (!vis2[j] && (k == -1 || dist2[j] < dist2[k]))
                    k = j;
            }
            if (dist2[k] == IMX) break;
            vis2[k] = true;
            for (auto j: v2[k]) {
                if (dist2[j.f] > dist2[k]+j.s) {
                    dist2[j.f] = dist2[k]+j.s;
                    p2[j.f] = k;
                }
            }
        }
        ll tmp = 0;
        vi path;
        for (int b = n; b != -1; b = p2[b]) {
            path.pb(b);
        }
        for (int b = 0; b < path.sz()-1; b++) {
            tmp += ar2[path[b]][path[b+1]];
        }
        ss = max(tmp, ss);
    }
    cout << ss-fs << '\n';
}

/* Stuff to look for
 * int overflow, array bounds
 * special cases (n=1)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 * GET RID OF DEBUGGING CODE BEFORE SUBMITTING
 */
