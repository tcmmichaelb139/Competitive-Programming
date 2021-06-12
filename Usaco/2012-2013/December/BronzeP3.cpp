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

int n, c;
map<int, int> mx;
map<int, int> my;
vc<pair<pi, pi>> v;
set<int> sx, sy;
vpi cowstemp;
bool cows[3050][3050];
bool ar[3050][3050];
bool vis[3050][3050];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
pi k;
int currsum;

int main() {
    IO("");

    cin >> n >> c;
    for (int i = 0; i < n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        sx.insert(a);
        sy.insert(b);
        sx.insert(c);
        sy.insert(d);
        v.pb({{a, b}, {c, d}});
    }
    for (int i = 0; i < c; i++) {
        int a, b;
        cin >> a >> b;
        cowstemp.pb({a, b});
        sx.insert(a);
        sy.insert(b);
    }
    int temp = 1;
    for (auto i: sx) {
        mx[i] = temp;
        temp += 2;
        k.f = temp;
    }
    temp = 1;
    for (auto i: sy) {
        my[i] = temp;
        temp += 2;
        k.s = temp;
    }
    for (int i = 0; i < c; i++) {
        cows[mx[cowstemp[i].f]][my[cowstemp[i].s]] = true;
    }
    for (int i = 0; i < n; i++) {
        if (mx[v[i].f.f] == mx[v[i].s.f])
            for (int j = min(my[v[i].f.s], my[v[i].s.s]); j <= max(my[v[i].s.s], my[v[i].f.s]); j++) {
                ar[mx[v[i].f.f]][j] = true;
            }
        else 
            for (int j = min(mx[v[i].f.f], mx[v[i].s.f]); j <= max(mx[v[i].s.f], mx[v[i].f.f]); j++) 
                ar[j][my[v[i].f.s]] = true;
    }
    int ans = 0;
    for (int i = 0; i < k.f*2; i++) {
        for (int j = 0; j < k.s*2; j++) {
            if (vis[i][j]) continue;
            currsum = 0;
            queue<pi> q;
            q.push({i, j});
            while (!q.empty()) {
                pi tmp = q.front();
                q.pop();
                if (cows[tmp.f][tmp.s]) currsum++;
                for (int i = 0; i < 4; i++) {
                    if (tmp.f+dx[i] < 0 || tmp.f+dx[i] > k.f || tmp.s+dy[i] > k.s || tmp.s+dy[i] < 0) continue;
                    if (!vis[tmp.f+dx[i]][tmp.s+dy[i]] && !ar[tmp.f+dx[i]][tmp.s+dy[i]]) {
                        q.push({tmp.f+dx[i], tmp.s+dy[i]});
                        vis[tmp.f+dx[i]][tmp.s+dy[i]] = true;
                    }
                }
            }
            ans = max(currsum, ans);
        }
    }

    cout << ans << '\n';
}

/* Stuff to look for
 * int overflow, array bounds
 * special cases (n=1)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 * GET RID OF DEBUGGING CODE
 */


