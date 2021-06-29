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
#define IMX INT_MAX 
#define IMN INT_MIN

void IO(string s = "") {
    ios_base::sync_with_stdio(0); cin.tie(0); 
    if (s.length()) {
        freopen((s+".in").c_str(),"r",stdin);
        freopen((s+".out").c_str(),"w",stdout);
    }
}
//}}}

int main() {
    IO("");

    int w, h;
    cin >> w >> h;
    cin.ignore();
    vc<vb> ar(2*h+2, vb(2*w+1, true));
    pi st1 = {-1, -1}, st2;
    for (int i = 0; i < 2*h+1; i++) {
        string s;
        getline(cin, s);
        for (int j = 0; j < 2*w+1; j++) {
            if ((j == 0 && s[j] == ' ') || (j == 2*w && s[j] == ' ') || (i == 0 && s[j] == ' ') || (i == 2*h && s[j] == ' ')) {
                if (st1.f != -1) st2 = {i, j};
                else st1 = {i, j};
            }
            if (s[j] == '+' || s[j] == '-' || s[j] == '|') {
                ar[i][j] = true;
            }
            else ar[i][j] = false;
        }
    }
    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};
    queue<pi> q;
    q.push(st1);
    int vis[2*h+2][2*w+2];
    memset(vis, false, sizeof(vis));
    vc<vi> dist(2*h+2, vi(2*w+2, IMX));
    vis[st1.f][st1.s] = true;
    dist[st1.f][st1.s] = 0;
    dist[st2.f][st2.s] = 0;
    int ans = 0;
    while (!q.empty()) {
        pi tmp = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            pi k = {tmp.f+dx[i], tmp.s+dy[i]};
            if (k.f < 0 || k.s < 0 || k.f >= 2*h+1 || k.s >= 2*w+1) continue;
            if (!vis[k.f][k.s] && !ar[k.f][k.s]) {
                q.push(k);
                dist[k.f][k.s] = min(dist[tmp.f][tmp.s]+1, dist[k.f][k.s]);
                vis[k.f][k.s] = true;
            }
        }
    }
    memset(vis, false, sizeof(vis));
    while (!q.empty()) q.pop();
    q.push(st2);
    while (!q.empty()) {
        pi tmp = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            pi k = {tmp.f+dx[i], tmp.s+dy[i]};
            if (k.f < 0 || k.s < 0 || k.f >= 2*h+1 || k.s >= 2*w+1) continue;
            if (!vis[k.f][k.s] && !ar[k.f][k.s]) {
                q.push(k);
                dist[k.f][k.s] = min(dist[tmp.f][tmp.s]+1, dist[k.f][k.s]);
                vis[k.f][k.s] = true;
            }
        }
    }
    for (int i = 0; i < 2*h+1; i++) {
        for (int j = 0; j < 2*w+1; j++) {
            if (!ar[i][j]) {
                ans = max(ans, dist[i][j]);
            }
        }
    }
    cout << (ans+1)/2 << '\n';
}

/* Stuff to look for
 * int overflow, array bounds
 * special cases (n=1)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 * GET RID OF DEBUGGING CODE BEFORE SUBMITTING
 */


