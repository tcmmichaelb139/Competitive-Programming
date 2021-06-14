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

int main() {
    IO("div7");

    int n;
    cin >> n;
    vi psum(n+1, 0);
    vpi v(n, {-1, -1});
    map<int, int> m;
    for (int i = 1; i <= n; i++) {
        int e;
        cin >> e;
        psum[i] = (psum[i-1]+e)%7;
        if (v[psum[i]].f == -1) 
            v[psum[i]].f = i;
        else 
            v[psum[i]].s = i;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, v[i].s-v[i].f);
    }
    cout << ans << '\n';
}

