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

void IO(string s = "") {
    ios_base::sync_with_stdio(0); cin.tie(0); 
    if (s.length()) {
        freopen((s+".in").c_str(),"r",stdin);
        freopen((s+".out").c_str(),"w",stdout);
    }
}

int main() {
    IO("");

    int n, x;
    cin >> n >> x;
    vpi v;
    for (int i = 0; i < n; i++) {
        int e;
        cin >> e;
        v.pb({e, i+1});
    }
    if (n < 3) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    sort(all(v));
    for (int i = 0; i < n; i++) {
        int l = 0, r = n-1;
        while (l < r) {
            int m = x-v[i].f;
            if (l != i && r != i && v[l].f+v[r].f == m) {
                cout << v[l].s << ' ' << v[r].s << ' ' << v[i].s << '\n';
                return 0;
            }
            if (v[l].f+v[r].f < m)
                l++;
            else
                r--;
        }
    }
    cout << "IMPOSSIBLE\n";
}
