#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); 

	int n;
	while (cin >> n && n != 0) {
		int mnx = -1e9, mxx = 1e9;
		int mny = -1e9, mxy = 1e9;
		int mnz = -1e9, mxz = 1e9;
		for (int i = 0; i < n; i++) {
			int x, y, z, l;
			cin >> x >> y >> z >> l;
			mnx = max(x, mnx);
			mxx = min(x+l, mxx);
			mny = max(y, mny);
			mxy = min(y+l, mxy);
			mnz = max(z, mnz);
			mxz = min(z+l, mxz);
		}
		int ans = (mxx-mnx)*(mxy-mny)*(mxz-mnz);
		if (ans < 0) cout << 0 << '\n';
		else cout << ans << '\n';
	}
}


/* Stuff to look for
 * int overflow, array bounds
 * special cases (n=1)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */

