
/*
ID: tcmmich1
TASK: preface
LANG: C++
*/
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
    IO("preface");

    int k;
    cin >> k;
    vi ans(7, 0);
    for (int i = 1; i <= k; i++) {
        int nt = 0;
        int temp = i;
        if (temp > 999) {
            int x = temp/1000;
            ans[6] += x;
            temp -= x*1000;
        }
        if (i > 99) {
            int x = temp/100;
            temp -= x*100;
            if (x == 0) ;
            else if (x < 4) {
                ans[4] += x;
            }
            else if (x == 4) {
                ans[5]++;
                ans[4]++;
            }
            else if (x == 5) {
                ans[5]++;
            }
            else if (x < 9) {
                ans[5]++;
                ans[4] += x-5;
            }
            else {
                ans[6]++;
                ans[4]++;
            }
        }
        if (i > 9) {
            int x = temp/10;
            temp -= x*10;
            if (x == 0) ;
            else if (x < 4) {
                ans[2] += x;
            }
            else if (x == 4) {
                ans[3]++;
                ans[2]++;
            }
            else if (x == 5) {
                ans[3]++;
            }
            else if (x < 9) {
                ans[3]++;
                ans[2] += x-5;
            }
            else {
                ans[4]++;
                ans[2]++;
            }
        }
        if (temp == 0) ;
        else if (temp < 4) {
            ans[0] += temp;
        }
        else if (temp == 4) {
            ans[1]++;
            ans[0]++;
        }
        else if (temp == 5) {
            ans[1]++;
        }
        else if (temp < 9) {
            ans[1]++;
            ans[0] += temp-5;
        }
        else {
            ans[2]++;
            ans[0]++;
        }
        /* cout << temp << '\n'; */
    /* if (ans[0]) cout << 'I' << ' ' << ans[0] << '\n'; */
    /* if (ans[1]) cout << 'V' << ' ' << ans[1] << '\n'; */
    /* if (ans[2]) cout << 'X' << ' ' << ans[2] << '\n'; */
    /* if (ans[3]) cout << 'L' << ' ' << ans[3] << '\n'; */
    /* if (ans[4]) cout << 'C' << ' ' << ans[4] << '\n'; */
    /* if (ans[5]) cout << 'D' << ' ' << ans[5] << '\n'; */
    /* if (ans[6]) cout << 'M' << ' ' << ans[6] << '\n'; */
    }
    if (ans[0]) cout << 'I' << ' ' << ans[0] << '\n';
    if (ans[1]) cout << 'V' << ' ' << ans[1] << '\n';
    if (ans[2]) cout << 'X' << ' ' << ans[2] << '\n';
    if (ans[3]) cout << 'L' << ' ' << ans[3] << '\n';
    if (ans[4]) cout << 'C' << ' ' << ans[4] << '\n';
    if (ans[5]) cout << 'D' << ' ' << ans[5] << '\n';
    if (ans[6]) cout << 'M' << ' ' << ans[6] << '\n';
}

/* Stuff to look for
 * int overflow, array bounds
 * special cases (n=1)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */

