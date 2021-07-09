/*
ID: tcmmich1
TASK: subset
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;

// template {{{
typedef long long ll;
typedef long double ld;
typedef double db;
typedef string str;

typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<ld, ld> pd;

#define ve vector
typedef ve<int> vi;
typedef ve<bool> vb;
typedef ve<ll> vl;
typedef ve<ld> vd;
typedef ve<string> vs;
typedef ve<pi> vpi;
typedef ve<pl> vpl;
typedef ve<pd> vpd;

#define sz(x) (int)((x).size())
#define bg(x) begin(x)
#define rbg(x) rbegin(x)
#define all(x) bg(x), end(x)
#define rall(x) rbg(x), rend(x)
#define pb push_back
#define eb emplace_back
#define pf push_front
#define rsz resize
#define ins insert

#define ub upper_bound
#define lb lower_bound

#define f first
#define s second
#define mp make_pair

#define ln length

template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;

const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

void IO(string s = "") {
    ios_base::sync_with_stdio(0); cin.tie(0); 
    if (s.length()) {
        freopen((s+".in").c_str(),"r",stdin);
        freopen((s+".out").c_str(),"w",stdout);
    }
} //}}}

int main() {
    IO("subset");
    
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i++)
        sum += i;
    if (sum&1) {
        cout << 0 << '\n';
        return 0;
    }
    ve<vl> dp(sum+1, vl(n+1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = sum/2; j >= 0; j--) {
            dp[j+i][i] += dp[j][i-1];
            dp[j][i] = dp[j][i-1];
        }
    }
    cout << dp[sum/2][n]/2 << '\n';
}

/* Stuff to look for 
 * int overflow, array bounds
 * special cases (n=1)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 * GET RID OF DEBUGGING CODE BEFORE SUBMITTING
 */
