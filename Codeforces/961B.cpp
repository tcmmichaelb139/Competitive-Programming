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
#define rsz resize
#define sz size
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
 
int N, K;
int at[100001], ak[100001];
 
int main() {
    IO("");
        
    cin >> N >> K;
    for (int i = 0; i < N; i++)
        cin >> at[i];
    for (int i = 0; i < N; i++)
        cin >> ak[i];
    int ans = 0; 
    int mxa = 0;
    vi pr(N);
    for (int i = 0; i < N; i++) {
        if (i) pr[i] += pr[i-1];
        if (ak[i] == 0) pr[i] += at[i];
        else ans += at[i];
    }
    for (int i = K-1; i < N; i++) {
        mxa = max(mxa, pr[i]-(i >= K ? pr[i-K] : 0));
    }
    cout << ans+mxa << '\n';
}
