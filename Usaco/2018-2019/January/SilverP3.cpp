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

bool cmp(pi a, pi b) {
    if (a.f == b.f) return a.s > b.s;
    return a.f < b.f;
}

int main() {
    IO("mountains");

    int n;
    cin >> n;
    vpi v;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.pb({a-b, a+b});
    }
    sort(all(v), cmp);
    int r = -1, ans = 0;
    for (int i = 0; i < n-1; i++) {
        if (v[i].s > r) {
            ans++;
            r = v[i].s;
        }
    }
    cout << max(ans, 1) << '\n';
}

