#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); 

    string s;
    cin >> s;
    int k = 0;
    while (true) {
        string s2 = s;
        if (s2 == "0") break;
        k++;
        int mx = 0;
        for (int i = 0; i < s2.length(); i++) {
            mx = max(mx, s2[i]-'0');
        }
        int is = stoi(s2);
        is -= mx;
        s = to_string(is);
    }
    cout << k << '\n';
}

/* Stuff to look for
 * int overflow, array bounds
 * special cases (n=1)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */
