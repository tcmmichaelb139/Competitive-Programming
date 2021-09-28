#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); 

    string s1;
    string s2;
    while (getline(cin, s1) && getline(cin, s2)) {
        stringstream s1s(s1);
        stringstream s2s(s2);
        vector<long long> c, x;
        while (true) {
            long long tmp;
            s1s >> tmp;
            if (!s1s) break;
            c.push_back(tmp);
        }
        while (true) {
            long long tmp;
            s2s >> tmp;
            if (!s2s) break;
            x.push_back(tmp);
        }
        for (int i = 0; i < x.size(); i++) {
            long long ans = 0;
            long long curr = 1;
            for (int j = c.size()-1; j >= 0; j--) {
                ans += curr*c[j];
                curr *= x[i];
            }
            cout << ans << " \n"[i+1 == x.size()];
        }
    }
}


/* Stuff to look for
 * int overflow, array bounds
 * special cases (n=1)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */

