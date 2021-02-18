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

#define pb push_back
#define pf push_front
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define ub upper_bound
#define lb lower_bound

#define f first
#define s second
#define mp make_pair

void IO(string s = "") {
    ios_base::sync_with_stdio(0); cin.tie(0); 
    if (s.length()) {
        freopen((s+".in").c_str(),"r",stdin);
        freopen((s+".out").c_str(),"w",stdout);
    }
}

vi v;

bool sumofpetals(int a, int b) {
    double x = 0;
    for (int i = a; i < b+1; i++) {
        x += v[i];
    }
    x /= b-a+1;
    for (int i = a; i < b+1; i++) {
        if (x == v[i]) return true;
    }
    return false;
}

int main() {
    IO("");

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int e;
        cin >> e;
        v.pb(e);
    }
    int ans = t;
    for (int i = 0; i < t; i++) 
        for (int j = i+1; j < t; j++) 
            if (sumofpetals(i, j)) ans++;
    cout << ans << '\n';
}
