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


const int MOD = 1e9+7;

int n;
vi dp(1000001, 0);

int dc2(int i) {
    if (i < 0) return 0;
    if (dp[i] != 0) return dp[i];
    if (i == 0) return 1;
    for (int j = 1; j <= 6; j++) {
        dp[i] += dc2(i-j);
        dp[i] %= MOD;
    }
    return dp[i];
}

int main() {
    IO("");

    cin >> n;
    cout << dc2(n) << '\n';
    /* iterative dp */
    /* fill(all(dp), 0); */
    /* dp[0] = 1; */
    /* for (int i = 0; i < n; i++) { */
    /*     for (int j = 1; j < 7; j++) { */
    /*         if (i+j <= n) { */
    /*             dp[i+j] += dp[i]; */
    /*             dp[i+j] %= MOD; */
    /*         } */
    /*     } */
    /* } */
    /* cout << dp[n] << '\n'; */
}
