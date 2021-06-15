#include <bits/stdc++.h>
#include <utility>

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

bool cmp(pi a, pi b) {
    return a.s < b.s;
}

int main() {
    IO("photo");

    int n, k;
    cin >> n >> k;
    vpi ve(k);
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);
        ve[i] = {a, b};
    }
    sort(all(ve), cmp);
    vpi vbe = ve;
    sort(all(vbe));
    map<pi, bool> vis;
    int ind = 0;
    int ans = 0;
    for (int i = 0; i < k; i++) {
        if (vis[{ve[i].f, ve[i].s}]) continue;
        ans++;
        vis[{ve[i].f, ve[i].s}] = true;
        for (int j = ind; j < k; j++) {
            if (vbe[j].f < ve[i].s) {
                vis[{vbe[j].f, vbe[j].s}] = true;
                ind = j;
            }
            else break;
        }
    }
    cout << ans+1 << '\n';
}
