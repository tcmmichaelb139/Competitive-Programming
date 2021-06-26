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

    int n, m;
    cin >> n >> m;
    vc<vb> ar(n+1, vb(m+1, false));
    vc<vb> vis(n+1, vb(m+1, false));
    pi s, e;
    for (int i = 0; i < n; i++) {
        string tmp;
        cin >> tmp;
        for (int j = 0; j < m; j++) {
            if (tmp[j] == '#') ar[i][j] = false;
            else ar[i][j] = true;
            if (tmp[j] == 'A') s = {i, j};
            if (tmp[j] == 'B') e = {i, j};
        }
    }
    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};
    vc<vi> dist(n, vi(m, 0));
    vc<vc<pair<pi, char>>> p(n, vc<pair<pi, char>>(m));
    queue<pi> q;
    q.push({s.f, s.s});
    vis[s.f][s.s] = true;
    p[s.f][s.s] = {{-1, -1}, '!'};
    while (!q.empty()) {
        pi tmp = q.front();
        q.pop();
        if (tmp.f == e.f && tmp.s == e.s) break;
        for (int i = 0; i < 4; i++) {
            pi k = {tmp.f+dx[i], tmp.s+dy[i]};
            if (k.f < 0 || k.s < 0 || k.f >= n || k.s >= m) continue;
            if (!vis[k.f][k.s] && ar[k.f][k.s]) {
                q.push({k.f, k.s});
                vis[k.f][k.s] = true;
                dist[k.f][k.s] = dist[tmp.f][tmp.s]+1;
                if (dx[i] == 1) p[k.f][k.s] = {tmp, 'D'};
                if (dx[i] == -1) p[k.f][k.s] = {tmp, 'U'};
                if (dy[i] == 1) p[k.f][k.s] = {tmp, 'R'};
                if (dy[i] == -1) p[k.f][k.s] = {tmp, 'L'};
            }
        }
    }
    if (!vis[e.f][e.s]) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    cout << dist[e.f][e.s] << '\n';
    vc<pair<pi, char>> path;
    for (pair<pi, char> k = p[e.f][e.s]; k.s != '!'; k = p[k.f.f][k.f.s])
        path.pb(k);
    reverse(all(path));
    for (auto i: path)
        cout << i.s;
    cout << '\n';
}
