#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

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
#define inf 1e9

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
    IO("pairup");

    int n;
    cin >> n;
    vpi v;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.pb({a, b});
    }
    sort(all(v), cmp);
    int l = 0, r = n-1;
    int ans = 0;
    while (l < r) {
        int x = min(v[l].f, v[r].f);

        v[l].f -= x;
        v[r].f -= x;
        ans = max(v[l].s+v[r].s, ans);
        if (v[l].f == 0)
            l++;
        if (v[r].f == 0)
            r--;
    }
    cout << ans << '\n';
}

