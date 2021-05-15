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

map<int, bool> m;

int main() {
    IO("");

    int n;
    cin >> n;
    vi v(n);
    int k = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (!m[v[i]]) k++;
        m[v[i]] = true;
    }
    if (k > 3) {
        cout << -1 << '\n';
    }
    else if (k == 1) {
        cout << 0 << '\n';
    }
    else if (k == 2) {
        int no = v[0];
        int second = 0;
        for (auto i: m) {
            if (i.f == no) continue;
            second = i.f;
        }
        if (abs(no-second)&1) 
            cout << abs(no-second) << '\n';
        else 
            cout << abs(no-second)/2 << '\n';
    }
    else {
        int f, s;
        int prev = 0;
        bool ok = false;
        bool ok2 = 0;
        for (auto i: m) {
            if (!ok) {
                ok = true;
                prev = i.f;
                continue;
            }
            if (ok && !ok2) {
                s = i.f-prev;
                prev = i.f;
                ok2 = true;
                continue;
            }
            f = i.f-prev;
        }
        if (f != s) cout << -1 << '\n';
        else cout << f << '\n';
    }
}
