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
    IO("angry");

    int n, k;
    cin >> n >> k;
    vi v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(all(v));
    int l = 0, r = IMX;
    while (l <= r) {
        int mid = l+(r-l)/2;
        int used = 0;
        int currsize = 0;
        int prev = 0;
        for (int i = 0; i < n; i++) {
            if (!i) {
                prev = v[i];
                continue;
            }
            currsize += v[i]-prev;
            if (currsize > mid*2) {
                currsize = 0;
                prev = v[i];
                used++;
            }
            //cout << currsize << '\n';
            prev = v[i];
        }
        used++;
        if (used <= k) r = mid-1;
        else l = mid+1;
    }
    cout << l << '\n';
}

/* Stuff to look for
 * int overflow, array bounds
 * special cases (n=1)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */
