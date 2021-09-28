#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); 

    double k;
    double s;
    while (cin >> k >> s) {
        cout << setprecision(0) << fixed << pow(s, 1/k) << '\n';
    }
}


/* Stuff to look for
 * int overflow, array bounds
 * special cases (n=1)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */

