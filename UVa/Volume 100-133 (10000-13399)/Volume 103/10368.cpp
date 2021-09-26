#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); 

    long long a, b;
    while (cin >> a >> b) {
        if (a == 0 && b == 0) break;
        if (min(a, b)*2 < max(a, b) || max(a, b)%min(a, b) == 0) {
            cout << "Stan wins\n";
            continue;
        }
        int tmp = 0;
        while (a != 0 && b != 0) {
            int k = min(a, b);
            if (k == a) 
                b -= k;
            else 
                a -= k;
            tmp++;
            if (min(a, b)*2 < max(a, b) || max(a, b)%min(a, b) == 0) {
                break;            
            }
        }
        tmp--;
        if (tmp&1) 
            cout << "Stan wins\n";
        else 
            cout << "Ollie wins\n";
    }
}


/* Stuff to look for
 * int overflow, array bounds
 * special cases (n=1)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */

